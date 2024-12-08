#include <gtest/gtest.h>
#include "../include/lab1.h"

std::string intToBinary(int n) {
    std::string binary = "";
    for(int i = 0; i < 32; i++) {
    if(n & (1 << i))
        binary = "1" + binary;
    else
        binary = "0" + binary;
    }
    return binary;
}

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(intToBinary(1) == "00000000000000000000000000000001");
                                   
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(intToBinary(2) == "00000000000000000000000000000010");
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(intToBinary(3) == "00000000000000000000000000000011");
}

TEST(test_04, basic_test_set)
{
    ASSERT_TRUE(intToBinary(5) == "00000000000000000000000000000101");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}