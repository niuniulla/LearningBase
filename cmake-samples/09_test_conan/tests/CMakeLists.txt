### setup googletest ###
find_package(GTest REQUIRED)

# gather all source files for testing under the current directory
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)
message(TEST_SOURCES=${TEST_SOURCES})

# # add the math library
# set( mathpath ${PROJECT_SOURCE_DIR}/math )
# set( helperpath ${PROJECT_SOURCE_DIR}/helper )
# include(${mathpath}/CMakeLists.txt)
# include(${helperpath}/CMakeLists.txt)

# executable source files
add_executable(test_main ${TEST_SOURCES})

# link libraries
target_link_libraries(test_main PRIVATE GTest::gtest_main)
target_link_libraries(test_main PRIVATE GTest::gmock_main)

target_link_libraries(test_main PUBLIC mymath)
target_link_libraries(test_main PUBLIC myhelper)

# enable tests
add_test(NAME tests COMMAND test_main)


