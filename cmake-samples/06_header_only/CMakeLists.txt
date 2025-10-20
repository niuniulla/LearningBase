cmake_minimum_required(VERSION 3.30)

# set the project name
project(cmake_minimal_executable LANGUAGES CXX)

# resolve libraries logic
add_subdirectory(math) # call my_project/algo/CMakeLists.txt
add_subdirectory(helper) # call my_project/helper/CMakeLists.txt

# declare the executable target
add_executable(app)
# add source files
target_sources(app PRIVATE example/main.cpp)

# link the libraries
target_link_libraries(app PRIVATE mymath myhelper)
