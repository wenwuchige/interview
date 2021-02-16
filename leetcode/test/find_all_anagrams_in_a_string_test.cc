#include "leetcode/sliding_window/find_all_anagrams_in_a_string.cc"
#include "third_party/gtest/include/gtest.h"

TEST(tmp, findAnagrams) {
  string s = "cbaebabacd";
  string p = "abc";
  vector<int> result = findAnagrams(s, p);
  vector<int> base = {0, 6};
  EXPECT_EQ(result.size(), base.size());
  for (int i = 0; i < result.size(); ++i) {
    EXPECT_EQ(result[i], base[i]);
  }
  // s = "abab";
  // p = "ab";
  // result = findAnagrams(s, p);
  // base = {0, 1, 2};
  // EXPECT_EQ(result.size(), base.size());
  // for (int i = 0; i < result.size(); ++i) {
  //   EXPECT_EQ(result[i], base[i]);
  // }
}
