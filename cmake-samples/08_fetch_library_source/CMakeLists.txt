cmake_minimum_required(VERSION 3.30)

# set the project name
project(cmake_minimal_executable LANGUAGES C CXX)

add_subdirectory(external)

# declare the executable target
add_executable(app)

# add source files
target_sources(app PRIVATE example/main.cpp)

# link the libraries
target_link_libraries(app PRIVATE mymath myhelper soil2 lua)

# define header directory if not done in external
target_include_directories(app PRIVATE
                           ${PROJECT_SOURCE_DIR}/external/include)