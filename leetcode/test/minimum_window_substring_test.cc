#include "leetcode/sliding_window/minimum_window_substring.cc"
#include "third_party/gtest/include/gtest.h"

TEST(tmp, minWindow) {
  string s = "ADOBECODEBANC";
  string t = "ABC";
  EXPECT_EQ(minWindow(s, t), "BANC");
  s = "a";
  t = "a";
  EXPECT_EQ(minWindow(s, t), "a");
}
