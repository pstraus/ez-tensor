#include "StaticMultiDimensionalArray.h"
#include <gtest/gtest.h>


TEST(TestStaticMultiDimensionalArray, atAssign)
{
    StaticMultiDimensionalArray<double, 3, 5, 6> testTensor;

    testTensor.at(1,2,3) = 4;

    EXPECT_DOUBLE_EQ(testTensor.at(1,2,3), 4.0);

}

TEST(TestStaticMultiDimensionalArray, rank)
{

    StaticMultiDimensionalArray<double, 3> testTensorRank1;
    StaticMultiDimensionalArray<int, 1, 2> testTensorRank2;
    StaticMultiDimensionalArray<uint, 3, 3, 3> testTensorRank3;
    StaticMultiDimensionalArray<float, 1,2,3,4> testTensorRank4;

    EXPECT_EQ(testTensorRank1.rank(), std::size_t(1));
    EXPECT_EQ(testTensorRank2.rank(), std::size_t(2));
    EXPECT_EQ(testTensorRank3.rank(), std::size_t(3));
    EXPECT_EQ(testTensorRank4.rank(), std::size_t(4));
}

int main(int argc, char** argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}