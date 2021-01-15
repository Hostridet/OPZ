#include "gtest/gtest.h"
#include "opz.h"


TEST(tested, t1)
{
    const char* str;
    str = "1 + 2";
    float result = GetResult(str);
    ASSERT_FLOAT_EQ(result, 3);
}

TEST(tested, t2)
{
    const char* str;
    str = "6 - 2";
    float result = GetResult(str);
    ASSERT_FLOAT_EQ(result, 4);
}

TEST(tested, t3)
{
    const char* str;
    str = "(3-1)*6";
    float result = GetResult(str);
    ASSERT_FLOAT_EQ(result, 12);
}

TEST(tested, t4)
{
    const char* str;
    str = "23 - 15 * 4 / 5";
    float result = GetResult(str);
    ASSERT_FLOAT_EQ(result, 11);
}

TEST(tested, t5)
{
    const char* str;
    str = "(1 + 5 ) * (2 - 3 * 4) / 4 - ( 5- 6)";
    float result = GetResult(str);
    ASSERT_FLOAT_EQ(result, 8);
}

TEST(tested, t6)
{
    const char* str;
    str = "17 - 10 / 5 * (4 + 2)";
    float result = GetResult(str);
    ASSERT_FLOAT_EQ(result, 7);
}

TEST(tested, t7)
{
    const char* str;
    str = "23 - 42 / 2";
    float result = GetResult(str);
    ASSERT_FLOAT_EQ(result, 2);
}

TEST(tested, t8)
{
    const char* str;
    str = "42/6 + (3 +2 * 4)";
    float result = GetResult(str);
    ASSERT_FLOAT_EQ(result, 18);
}

TEST(tested, t9)
{
    const char* str;
    str = "934 - 23 * 23";
    float result = GetResult(str);
    ASSERT_FLOAT_EQ(result, 405);
}

TEST(tested, t10)
{
    const char* str;
    str = "1                             + 23           -         54";
    float result = GetResult(str);
    ASSERT_FLOAT_EQ(result, -30);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}