cmake_minimum_required(VERSION 3.28)

# Project Name
project(ThermodynamicSimulator)

# Set the C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Turn on Qt's automation
set(CMAKE_AUTOMOC ON) # Handles Signals/Slots
set(CMAKE_AUTOUIC ON) # Handles .ui files
set(CMAKE_AUTORCC ON) # Handles resources

find_package(Qt6 REQUIRED COMPONENTS Widgets Charts) # Find the Qt library packages

# Define your source files
file(GLOB_RECURSE SOURCES 

    # COMPUTATION SRC FILES
    "computation/algorithms/*.cpp"
    "computation/cycles/*.cpp"
    "computation/tools/*.cpp"
    "computation/*.cpp" 
    
    # GUI SRC FILES
    "gui/ui/*.ui"
    "gui/src/headers/*.h"
    "gui/src/cpp_files/*.cpp"

    #IMAGES SRC FILE
    "images.qrc"

    # MAIN SRC FILE
    "main.cpp"
)

# Define where the compiler should look for header files (.h)
include_directories(
    "computation"
    "computation/algorithms"
    "computation/cycles"
    "computation/tools"
)

# 6. Create the executable application
add_executable(sim ${SOURCES})

# Tell AUTOUIC to look in the 'gui/ui' folder if it can't find the .ui file next to the .cpp
set_property(TARGET sim APPEND PROPERTY AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/gui/ui")

target_compile_definitions(sim PRIVATE PROJECT_PATH="${CMAKE_CURRENT_SOURCE_DIR}") # Define a Macro containing the root directory of this project

target_link_libraries(sim PRIVATE Qt6::Widgets Qt6::Charts) # Link excecutable to the Qt6 library