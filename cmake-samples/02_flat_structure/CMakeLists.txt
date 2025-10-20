cmake_minimum_required(VERSION 3.30)

# set the project name
project(cmake_minimal_executable LANGUAGES CXX)

# declare the executable target
add_executable(app)

# add source files
target_sources(app PRIVATE main.cpp util.cpp util.h)

# install
install(TARGETS app)