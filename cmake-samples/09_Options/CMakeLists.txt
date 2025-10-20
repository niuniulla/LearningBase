cmake_minimum_required(VERSION 3.30)

# set the project name
project(cmake_minimal_executable LANGUAGES C CXX)

# add options
option(USE_MYMATH "Use my mathlib implementation" OFF)
set(USE_MYMATH FALSE CACHE BOOL)
message("mymath: ${USE_MYMATH}")
add_subdirectory(external)

# declare the executable target
add_executable(app)

# add source files
target_sources(app PRIVATE example/main.cpp)

# link the libraries
if (USE_MYMATH)
    message("use mymath")
    target_link_libraries(app PRIVATE mymath myhelper soil2 lua)
else()
    message("use default math")
    target_link_libraries(app PRIVATE myhelper soil2 lua)
endif()

# define header directory if not done in external
# target_include_directories(app PRIVATE
                        #    ${PROJECT_SOURCE_DIR}/external/include)