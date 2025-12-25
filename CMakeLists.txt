cmake_minimum_required(VERSION 3.28)

# 1. Name your project
project(ThermodynamicSimulator)

# 2. Set the C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 3. Turn on Qt's magic automation
set(CMAKE_AUTOMOC ON) # Handles Signals/Slots
set(CMAKE_AUTOUIC ON) # Handles .ui files
set(CMAKE_AUTORCC ON) # Handles resources

find_package(Qt6 REQUIRED COMPONENTS Widgets)

# 4. Define your source files
file(GLOB_RECURSE SOURCES 
    "computation/algorithms/*.cpp"
    "computation/cycles/*.cpp"
    "computation/tools/*.cpp"
    "computation/*.cpp" 
    
    "gui/ui/*.ui"
    "gui/src/headers/*.h"
    "gui/src/cpp_files/*.cpp"

    "images.qrc"
    
    "main.cpp"
)

# 5. Define where the compiler should look for header files (.h)
include_directories(
    "computation"
    "computation/algorithms"
    "computation/cycles"
    "computation/tools"
    "gui/src/headers"
    # Note: You generally do NOT need to add the build directory 
    # for ui_*.h files here; CMake handles that automatically with AUTOUIC.
)

# 6. Create the executable application
add_executable(sim ${SOURCES})

# --- CRITICAL FIX START ---
# Tell AUTOUIC to look in the 'gui/ui' folder if it can't find the .ui file next to the .cpp
set_property(TARGET sim APPEND PROPERTY AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/gui/ui")
target_compile_definitions(sim PRIVATE PROJECT_PATH="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(sim PRIVATE Qt6::Widgets)