#!/bin/bash

# ==========================================
# Qt6 Build Automation & Setup Script
# Thermodynamic Simulator Project
# ==========================================

# 1. STOP ON ERROR
set -e

# ==========================================
# CONFIGURATION
# ==========================================

BUILD_TYPE="Debug"
BUILD_DIR="build"

# Define all required Qt6 modules here. 
# Common options: Core Gui Widgets Charts Network Sql PrintSupport Svg Xml
REQUIRED_QT_MODULES=("Core" "Gui" "Widgets" "Charts")

# ==========================================
# INSTALLATION HELPERS
# ==========================================

install_packages() {
    local missing_item=$1
    echo "----------------------------------------------------"
    echo "   Missing dependency: $missing_item"
    echo "   Attempting automatic installation..."
    echo "----------------------------------------------------"
    
    read -p "Do you want to proceed with installation? (y/n) " -n 1 -r
    echo
    if [[ ! $REPLY =~ ^[Yy]$ ]]; then
        echo " Installation aborted by user. Exiting."
        exit 1
    fi

    if [ "$(uname)" == "Darwin" ]; then
        # macOS (Homebrew)
        if ! command -v brew &> /dev/null; then
            echo " Error: Homebrew is required for auto-install on macOS."
            exit 1
        fi
        echo " Detected macOS. Installing qt..."
        # brew install qt usually covers Core, Gui, Widgets, Charts, Network
        brew install qt cmake
        
    elif command -v apt-get &> /dev/null; then
        # Debian/Ubuntu (apt)
        echo " Detected Debian/Ubuntu. Using apt-get..."
        sudo apt-get update
        
        # Base development tools
        sudo apt-get install -y build-essential cmake
        
        # Qt6 Base (Core, Gui, Widgets, Network, Sql, PrintSupport)
        sudo apt-get install -y qt6-base-dev qt6-base-private-dev
        
        # Additional Modules (Add as needed)
        sudo apt-get install -y libqt6charts6-dev libqt6svg6-dev
        
    elif command -v dnf &> /dev/null; then
        # Fedora/RHEL (dnf)
        echo " Detected Fedora. Using dnf..."
        sudo dnf install -y gcc-c++ make cmake
        
        # Qt6 Base
        sudo dnf install -y qt6-qtbase-devel
        
        # Additional Modules
        sudo dnf install -y qt6-qtcharts-devel qt6-qtsvg-devel
        
    else
        echo " Error: Unsupported Package Manager."
        echo " Please manually install: Qt6 (Base + Charts) and CMake."
        exit 1
    fi
    
    echo " Installation attempts finished. Re-verifying..."
}

# ==========================================
# DEPENDENCY CHECKS (CMAKE PROBE)
# ==========================================

# This function creates a tiny temporary CMake project to test 
# if the library is actually loadable by the build system.
verify_qt_module() {
    local module=$1
    local temp_dir=".dependency_check_tmp"
    
    # Create temp directory
    mkdir -p "$temp_dir"
    
    # Create a dummy CMakeLists.txt that tries to find the specific module
    cat <<EOF > "$temp_dir/CMakeLists.txt"
cmake_minimum_required(VERSION 3.16)
project(DepCheck LANGUAGES CXX)
find_package(Qt6 COMPONENTS $module REQUIRED)
EOF

    # Attempt to configure this dummy project silently
    # We use 'cmake -S . -B .' inside the temp dir
    if cmake -S "$temp_dir" -B "$temp_dir" &> /dev/null; then
        # Cleanup
        rm -rf "$temp_dir"
        return 0 # Success
    else
        # Cleanup
        rm -rf "$temp_dir"
        return 1 # Failure
    fi
}

check_dependencies() {
    echo "--- Checking System Dependencies ---"
    echo

    # 1. CHECK FOR COMPILER
    if ! command -v g++ &> /dev/null && ! command -v clang++ &> /dev/null; then
        echo " [MISSING] C++ Compiler"
        install_packages "C++ Compiler"
    else
        echo " [OK] C++ Compiler found"
    fi

    # 2. CHECK FOR CMAKE
    if ! command -v cmake &> /dev/null; then
        echo " [MISSING] CMake"
        install_packages "CMake"
    else
        echo " [OK] CMake found"
    fi

    # 3. CHECK QT MODULES LOOP
    echo "--- Checking Qt6 Libraries ---"
    
    # If the user has defined CMAKE_PREFIX_PATH, print it for debugging
    if [ ! -z "$CMAKE_PREFIX_PATH" ]; then
        echo " Using Custom Qt Path: $CMAKE_PREFIX_PATH"
    fi

    local missing_modules=false

    for module in "${REQUIRED_QT_MODULES[@]}"; do
        if verify_qt_module "$module"; then
            echo " [OK] Qt6$module found"
        else
            echo " [MISSING] Qt6$module not found (or CMake cannot find it)"
            missing_modules=true
        fi
    done

    if [ "$missing_modules" = true ]; then
        echo
        echo " Some Qt modules are missing."
        install_packages "Qt6 Libraries"
        
        # Re-check after install attempt
        echo "--- Re-verifying after installation ---"
        for module in "${REQUIRED_QT_MODULES[@]}"; do
            if ! verify_qt_module "$module"; then
                echo " Error: Qt6$module is still missing after installation attempt."
                echo " You may need to export CMAKE_PREFIX_PATH if you installed Qt manually."
                exit 1
            fi
        done
    fi
}

# ==========================================
# EXECUTION FLOW
# ==========================================

# 1. Verify Dependencies
check_dependencies

echo
echo "--- Starting Build Process for $BUILD_TYPE ---"

# 2. Create Build Directory
if [ ! -d "$BUILD_DIR" ]; then
    mkdir -p "$BUILD_DIR"
fi

# 3. Configure (CMake)
# We pass the list of required components to the main CMakeLists if needed, 
# but usually, the CMakeLists.txt handles that. Here we just configure.
echo "--- Configuring project ---"
if ! cmake -S . -B "$BUILD_DIR" -DCMAKE_BUILD_TYPE=$BUILD_TYPE; then
    echo " Configuration failed."
    exit 1
fi

# 4. Compile
echo
echo "--- Compiling ---"
if ! cmake --build "$BUILD_DIR" --parallel; then
    echo " Compilation failed."
    exit 1
fi

# Exporting QPA Platform (Fix for WSL2/Linux display issues)
# Only applies if we are actually on Linux
if [ "$(uname)" == "Linux" ]; then
    export QT_QPA_PLATFORM=xcb
fi

echo
echo "=========================================="
echo "Build Complete!"
echo "Executable is located in: $BUILD_DIR/"
echo "To run: ./$BUILD_DIR/sim"  # Adjust 'sim' if your target name is different
echo "=========================================="