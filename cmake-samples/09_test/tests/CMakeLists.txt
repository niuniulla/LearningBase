if(TEST_GOOGLE)
  ### setup googletest ###
  include(FetchContent)
  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG b514bdc898e2951020cbdca1304b75f5950d1f59
  )

  FetchContent_MakeAvailable(googletest)

  # gather all source files for google testing under the current directory
  file(GLOB_RECURSE GTEST_SOURCES LIST_DIRECTORIES false "**/test*.cpp")
  message(GTEST_SOURCES=${GTEST_SOURCES})

  # executable source files for gtest
  add_executable(test_main ${GTEST_SOURCES})

  # link libraries for gtest
  target_link_libraries(test_main PRIVATE GTest::gtest_main)
  target_link_libraries(test_main PRIVATE GTest::gmock_main)
  target_link_libraries(test_main PUBLIC mymath)
  target_link_libraries(test_main PUBLIC myhelper)

  # enable gtest
  add_test(NAME gtests COMMAND test_main)
else()
  # Add CTest executable
  add_executable(ctest_arithmetic math/ctestArithmetic.cpp)
  target_link_libraries(ctest_arithmetic PUBLIC mymath)
  add_test(NAME ctest_arithmetic COMMAND ctest_arithmetic)

  # Add CTest helper executable
  add_executable(ctest_helper helper/ctestHelper.cpp)
  target_link_libraries(ctest_helper PUBLIC myhelper)
  add_test(NAME ctest_helper COMMAND ctest_helper)
endif()