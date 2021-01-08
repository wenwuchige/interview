#include "leetcode/sort/sort_an_array.cc"
#include "third_party/gtest/include/gtest.h"
#include <vector>

class SortTest : public testing::Test {
public:
  std::vector<int> input1_ = {5, 2, 3, 1};
  std::vector<int> input2_ = {5, 1, 1, 2, 0, 0};
};

TEST_F(SortTest, InsertSort) {
  auto result = InsertSort(input1_);
  EXPECT_EQ(result[0], 1);
  EXPECT_EQ(result[1], 2);
  EXPECT_EQ(result[2], 3);
  EXPECT_EQ(result[3], 5);
  result = InsertSort(input2_);
  EXPECT_EQ(result[0], 0);
  EXPECT_EQ(result[1], 0);
  EXPECT_EQ(result[2], 1);
  EXPECT_EQ(result[3], 1);
  EXPECT_EQ(result[4], 2);
  EXPECT_EQ(result[5], 5);
};

TEST_F(SortTest, QuickSort) {
  auto result = QuickSort(input1_);
  EXPECT_EQ(result[0], 1);
  EXPECT_EQ(result[1], 2);
  EXPECT_EQ(result[2], 3);
  EXPECT_EQ(result[3], 5);
  result = QuickSort(input2_);
  EXPECT_EQ(result[0], 0);
  EXPECT_EQ(result[1], 0);
  EXPECT_EQ(result[2], 1);
  EXPECT_EQ(result[3], 1);
  EXPECT_EQ(result[4], 2);
  EXPECT_EQ(result[5], 5);
}
