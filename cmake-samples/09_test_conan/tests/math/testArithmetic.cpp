#include "gtest/gtest.h"
#include "math/arithmetic.h"

// test class constructor
TEST(math_test, constructor)
{
    Rect r;
    EXPECT_EQ(r.getLength(), 0);
    EXPECT_EQ(r.getHeight(), 0);
    EXPECT_EQ(r.getBase().first, 0);
    EXPECT_EQ(r.getBase().second, 0);
}
// test class destructor with arguments
TEST(math_test, constructor_with_arg)
{
    Rect r{std::pair<int, int>(1, 2), 5, 6};
    EXPECT_EQ(r.getLength(), 5);
    EXPECT_EQ(r.getHeight(), 6);
    EXPECT_EQ(r.getBase().first, 1);
    EXPECT_EQ(r.getBase().second, 2);
}

TEST(math_test, arithmetic)
{
    EXPECT_EQ(Arithmetic::add(2, 3), 5);
    EXPECT_EQ(Arithmetic::multiply(2, 3), 6);
}