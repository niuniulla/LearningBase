

# declare the executable target
add_executable(app)
# add source files
target_sources(app PRIVATE main.cpp)

# link the libraries
target_link_libraries(app PUBLIC mymath myhelper)

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