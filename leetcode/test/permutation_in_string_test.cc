#include "leetcode/sliding_window/permutation_in_string.cc"
#include "third_party/gtest/include/gtest.h"

TEST(tmp, checkInclusion) {
  string s1 = "ab";
  string s2 = "eidbaooo";
  EXPECT_TRUE(checkInclusion(s1, s2));
  s1 = "ab";
  s2 = "eidboaoo";
  EXPECT_FALSE(checkInclusion(s1, s2));
  s1 = "a";
  s2 = "ab";
  EXPECT_TRUE(checkInclusion(s1, s2));
  s1 = "r";
  s2 = "pilmtnzraxj";
  EXPECT_TRUE(checkInclusion(s1, s2));
}
