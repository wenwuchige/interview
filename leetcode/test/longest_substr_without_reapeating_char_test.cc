#include "leetcode/sliding_window/longest_substr_without_reapeating_char.cc"
#include "third_party/gtest/include/gtest.h"
TEST(tmp, lengthOfLongestSubstring) {
  string s = "abcabcbb";
  EXPECT_EQ(lengthOfLongestSubstring(s), 3);
  s = "bbbbb";
  EXPECT_EQ(lengthOfLongestSubstring(s), 1);
  s = "pwwkew";
  EXPECT_EQ(lengthOfLongestSubstring(s), 3);
  s = "au";
  EXPECT_EQ(lengthOfLongestSubstring(s), 2);
  s = "tmmzuxt";
  EXPECT_EQ(lengthOfLongestSubstring(s), 5);
}
