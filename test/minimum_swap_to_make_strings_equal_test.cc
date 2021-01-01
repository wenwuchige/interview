#include "minimum_swap_to_make_strings_equal.cc"
#include "third_party/gtest/include/gtest.h"
#include <iostream>
TEST(minimumSwapTest, minimumSwapx) {
  std::string s1 = "xx";
  std::string s2 = "yy";
  std::cout << "here" << std::endl;
  ASSERT_EQ(minimumSwap(s1, s2), 1);
  s1 = "xy";
  s2 = "yx";
  ASSERT_EQ(minimumSwap(s1, s2), 2);
  s1 = "xx";
  s2 = "xy";
  ASSERT_EQ(minimumSwap(s1, s2), -1);
  s1 = "xxyyxyxyxx";
  s2 = "xyyxyxxxyx";
  ASSERT_EQ(minimumSwap(s1, s2), 4);
}
