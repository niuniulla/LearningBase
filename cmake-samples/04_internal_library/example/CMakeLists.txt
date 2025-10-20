# declare the executable target
add_executable(app)
# add source files
target_sources(app PRIVATE main.cpp)

# link the libraries
target_link_libraries(app PUBLIC mymath myhelper)