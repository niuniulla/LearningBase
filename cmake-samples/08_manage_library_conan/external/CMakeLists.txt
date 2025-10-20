add_library(mymath STATIC IMPORTED GLOBAL)

# import mymath library
set_target_properties(mymath 
                      PROPERTIES 
                      IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/lib/libmymath.a")

target_include_directories(mymath INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# import myhelper library
add_library(myhelper SHARED IMPORTED GLOBAL)

set_target_properties(myhelper
                      PROPERTIES 
                      IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/lib/libmyhelper.so")

target_include_directories(myhelper INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)


# fetch libraries
# include fetchcontent functions since they are not in the default cmake package
include(FetchContent)

# set the fetch directory to be populated
set(FETCHCONTENT_BASE_DIR ${PROJECT_SOURCE_DIR}/external/soil2)

# set the repository info for download for SOIL2
FetchContent_Declare(
  soil2
  GIT_REPOSITORY https://github.com/SpartanJ/SOIL2.git
  GIT_TAG 0823470d7fbddca4c2b130264d14b6294227be2c
)

# stream process the fetch logic
# this will do:
#   - populate the content: download the content from the repository(or other sources: eg. zip, file)
#   - add to the main build: try to locate the cmake file and add to the main build tree
FetchContent_MakeAvailable(soil2)

# # set the repository info for download for lua
# set(FETCHCONTENT_BASE_DIR ${PROJECT_SOURCE_DIR}/external/lua)
# FetchContent_Declare(
#   lua
#   GIT_REPOSITORY https://github.com/lua/lua.git
#   GIT_TAG 267ef461d0b13aa28d667f12d1a61452c9db529c
# )

# # since lua has no cmake file, this will only populate the content
# FetchContent_MakeAvailable(lua)

# # build lua library without provided CMakeLists.txt
# # find all source files list and assign it to variable lua_files
# FILE(GLOB_RECURSE lua_files LIST_DIRECTORIES false $${lua_SOURCE_DIR}/*.c ${lua_SOURCE_DIR}/*.h)

# # set the language since lua is in C
# set_target_properties(lua PROPERTIES LINKER_LANGUAGE C)

# # create lua library with the source files
# add_library(lua ${lua_files})
# if (WIN32)
#   target_compile_definitions(lua PRIVATE LUA_USE_WINDOWS)
# endif()

# if (UNIX)
#   target_compile_definitions(lua PRIVATE LUA_USE_LINUX)
#   target_link_libraries(lua PRIVATE dl)
# endif()
# # define the include path
# target_include_directories(lua PUBLIC ${lua_SOURCE_DIR})