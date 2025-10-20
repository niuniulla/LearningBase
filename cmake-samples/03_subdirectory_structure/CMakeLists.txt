cmake_minimum_required(VERSION 3.30)

# set the project name
project(cmake_minimal_executable LANGUAGES CXX)

# declare the executable target
add_executable(app)
# add source files
target_sources(app PRIVATE main.cpp)

# resolve the subdirectories' logic
add_subdirectory(helper)
add_subdirectory(math)
# By uncomment this, in main we can include the headers in the helper
# and math directories (eg. include "util.h").
# target_include_directories(app 
#                            PRIVATE 
#                            "${PROJECT_SOURCE_DIR}/helper"
#                            "${PROJECT_SOURCE_DIR}/math")

# install
install(TARGETS app)
