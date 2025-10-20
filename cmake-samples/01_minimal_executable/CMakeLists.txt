cmake_minimum_required(VERSION 3.30)

# set the project name
project(cmake_minimal_executable LANGUAGES CXX)


# define the executable target and add all concerning files
# If there are other .h or .cpp file, just add them
# after main.cpp separated by space.
add_executable(app main.cpp)

# Comment:
# This is not the only way to do it but this is the 
# minimal setup of a project with all source files
# in the project root directory.

# install(TARGETS app)

# set(ENV{PATH} "$ENV{PATH}:/opt/myDir")
# message("Qingyi2" $ENV{PATH})

# set(testVar ON CACHE BOOL "for testing")
# message(Qingyi ${testVar})

# unset(testVar CACHE)
