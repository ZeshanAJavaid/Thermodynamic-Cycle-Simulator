#!/bin/bash

# ==========================================
# Qt6 Build Automation & Setup Script
# For Thermodynamic Simulator Project
# ==========================================

# 1. STOP ON ERROR
set -e

# ==========================================
# CONFIGURATION
# ==========================================

BUILD_TYPE="Debug"
BUILD_DIR="build"

# ==========================================
# INSTALLATION HELPERS
# ==========================================

# Function to install packages based on OS
install_packages() {
    echo "----------------------------------------------------"
    echo "   Missing dependencies detected."
    echo "   Attempting to install: $1"
    echo "----------------------------------------------------"
    
    read -p "Do you want to proceed with installation? (y/n) " -n 1 -r
    echo
    if [[ ! $REPLY =~ ^[Yy]$ ]]; then
        echo " Installation aborted by user. Exiting."
        exit 1
    fi

    if [ "$(uname)" == "Darwin" ]; then
        # macOS Installation (Homebrew)
        if ! command -v brew &> /dev/null; then
            echo " Error: Homebrew is required for auto-install on macOS."
            exit 1
        fi
        echo " Detected macOS. Using Homebrew..."
        brew install $2
        
    elif command -v apt-get &> /dev/null; then
        # Debian/Ubuntu Installation (apt)
        echo " Detected Debian/Ubuntu. Using apt-get..."
        echo "sudo access is required to install packages."
        sudo apt-get update
        sudo apt-get install -y $3
        
    elif command -v dnf &> /dev/null; then
        # Fedora/RHEL Installation (dnf)
        echo " Detected Fedora. Using dnf..."
        echo "sudo access is required to install packages."
        sudo dnf install -y $4
        
    else
        echo " Error: Could not detect a supported package manager (apt, dnf, or brew)."
        echo "   Please install the following manually: $1"
        exit 1
    fi
    
    echo " Installation logic finished. Re-checking..."
}

# ==========================================
# DEPENDENCY CHECKS
# ==========================================

check_dependencies() {
    echo "--- Checking System Dependencies ---"
    echo

    # 1. CHECK FOR C++ COMPILER & MAKE
    if ! command -v g++ &> /dev/null && ! command -v clang++ &> /dev/null; then
        echo " C++ Compiler not found."
        install_packages "C++ Compiler & Make" "gcc" "build-essential" "gcc-c++ make"
    else
        echo " C++ Compiler found."
    fi

    sleep 1

    # 2. CHECK FOR CMAKE
    if ! command -v cmake &> /dev/null; then
        echo " CMake not found."
        install_packages "CMake" "cmake" "cmake" "cmake"
    else
        echo " CMake found."
    fi

    sleep 1

    # 3. CHECK FOR QT6
    # We look for qmake6 or qmake.
    QT_FOUND=false
    
    if command -v qmake6 &> /dev/null; then
        QT_FOUND=true
    elif command -v qmake &> /dev/null; then
        QMAKE_VERSION=$(qmake -query QT_VERSION)
        if [[ "$QMAKE_VERSION" == 6.* ]]; then
            QT_FOUND=true
        fi
    fi

    sleep 1

    if [ "$QT_FOUND" = false ]; then
        # If user defined a custom path manually in the script, we skip install
        if [ ! -z "$CMAKE_PREFIX_PATH" ]; then
            echo "ℹ  Qt tools not in global PATH, but CMAKE_PREFIX_PATH is set. Assuming valid."
        else
            echo " Qt6 not found."
            # Note: 'qt6-base-dev' is the standard Ubuntu package name. 
            # 'qt6-base-private-dev' is sometimes needed for internal headers but usually base-dev is enough.
            install_packages "Qt6 Development Libraries" "qt6" "qt6-base-dev qt6-base-private-dev" "qt6-qtbase-devel"
        fi
    else
        echo " Qt6 found."
    fi

    sleep 1
}

# ==========================================
# EXECUTION FLOW
# ==========================================

# 1. Verify and Install Dependencies
check_dependencies

echo
echo "--- Starting Build Process for $BUILD_TYPE ---"

# 2. Create Build Directory
if [ ! -d "$BUILD_DIR" ]; then
    echo
    echo "Creating build directory..."
    mkdir -p "$BUILD_DIR"
fi

# 3. Navigate to Build Directory
cd "$BUILD_DIR"

sleep 1

# 4. Configure (CMake)
# We add a check here just in case CMake fails even after installation
echo
echo "--- Configuring with CMake ---"
echo
if ! cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE ..; then
    echo " CMake Configuration failed." 
    echo "   This usually means a specific Qt module (like Widgets or Gui) is missing."
    echo "   Ensure specific Qt modules are installed."
    exit 1
fi

sleep 1

# 5. Compile
echo
echo "--- Compiling... ---"
echo
cmake --build . --parallel

sleep 1

export QT_QPA_PLATFORM=xcb


echo
echo "=========================================="
echo "Build Complete!"
echo "Executable is located in: $BUILD_DIR/"
echo "To run, type: ./$BUILD_DIR/sim"
echo "=========================================="