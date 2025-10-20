cmake_minimum_required(VERSION 3.30)

# set the project name
project(cmake_minimal_executable LANGUAGES CXX)

# send all executables to the bin folder in the build
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# resolve libraries logic
add_subdirectory(math) # call my_project/algo/CMakeLists.txt
add_subdirectory(helper) # call my_project/helper/CMakeLists.txt
add_subdirectory(example)

# add tests
set(TEST_GOOGLE true CACHE BOOL "use google test") # to swith between test types
enable_testing() # creates ctest configuration file in the build directory
add_subdirectory(tests)

# if we do simply:
# install(TARGETS app)
# as before, we will get error:
# bin/app: error while loading shared libraries: libmyhelper.so: 
# cannot open shared object file: No such file or directory.

# So we need set INSTALL_RPATH which is a target property 
# specifying the RPATH entries to be used for installed binaries.
set_target_properties(app 
                      PROPERTIES
                      INSTALL_RPATH "$ORIGIN/../lib" # path to executable
    )
install(TARGETS app
        EXPORT appTargets
        )
set(rpath "")
get_target_property(rpath app INSTALL_RPATH)