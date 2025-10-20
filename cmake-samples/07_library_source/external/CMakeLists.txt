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

# add soil2 logic, this will call the CMakeLists.txt of SOIL2 project
add_subdirectory(SOIL2)

# build lua library without provided CMakeLists.txt
# find all source files list and assign it to variable lua_files
FILE(GLOB_RECURSE lua_files LIST_DIRECTORIES false ${CMAKE_CURRENT_SOURCE_DIR}/lua/*.c ${CMAKE_CURRENT_SOURCE_DIR}/lua/*.h)
# create lua library with the source files
add_library(lua ${lua_files})
if (WIN32)
  target_compile_definitions(lua PRIVATE LUA_USE_WINDOWS)
endif()

if (UNIX)
  target_compile_definitions(lua PRIVATE LUA_USE_LINUX)
  target_link_libraries(lua PRIVATE dl)
endif()
# define the include path
target_include_directories(lua PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lua)