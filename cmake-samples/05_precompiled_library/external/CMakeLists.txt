add_library(mymath STATIC IMPORTED GLOBAL)

set_target_properties(mymath 
                      PROPERTIES 
                      IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/lib/libmymath.a")

target_include_directories(mymath INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(myhelper SHARED IMPORTED GLOBAL)

set_target_properties(myhelper
                      PROPERTIES 
                      IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/lib/libmyhelper.so")

target_include_directories(myhelper INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Since CMake doesn't allow to install IMPORTED libraries as TARGETS,
# we can just copy the file manually to the install directory.
# But this can be tedious for bigger projects

# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/lib/libmyhelper.so" DESTINATION lib)

# Otherwise, we could modify the cmake file for our executable target
# to find and include the library that we will explore later.
# Here, for simplicity, we can just use a subcommand of install to handle
# imported libraries for install.
install(IMPORTED_RUNTIME_ARTIFACTS myhelper)
