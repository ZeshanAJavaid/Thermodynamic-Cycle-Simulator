# 1. Name your project
project(ThermodynamicSimulator)

# 2. Ss)et the C++ Standard (C++17 is a good default for modern project
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 3. Define your source files
# We need to grab the files from all your folders
file(GLOB_RECURSE SOURCES 
    "computation/algorithms/*.cpp"
    "computation/cycles/*.cpp"
    "computation/tools/*.cpp"
    "computation/*.cpp" 
    # Choose ONE main file below. I've commented out the root one for now.
    "main.cpp" 
)

# 4. Define where the compiler should look for header files (.h)
include_directories(
    "computation"
    "computation/algorithms"
    "computation/cycles"
    "computation/tools"
)

# 5. Create the executable application
add_executable(sim ${SOURCES})