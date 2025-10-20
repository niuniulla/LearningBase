#include "helper/util.h"

#include "gtest/gtest.h"
#include <string>

TEST(helper_test, print)
{
    testing::internal::CaptureStdout();
    Util::print("this is a test");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "this is a test"); 
}

TEST(helper_test, print_int)
{
    testing::internal::CaptureStdout();
    Util::print(2);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "The integer is 2\n");
}