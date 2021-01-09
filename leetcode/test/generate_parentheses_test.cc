#include "leetcode/back_track/generate_parentheses.cc"
#include "third_party/gtest/include/gtest.h"
#include <algorithm>
TEST(GenerateParentheses, generateParenthesis) {
  int n = 0;
  auto result = generateParenthesis(n);
  ASSERT_EQ(result.size(), 0);
  n = 1;
  result = generateParenthesis(n);
  ASSERT_EQ(result.size(), 1);
  ASSERT_TRUE(std::find(result.begin(), result.end(), "()") != result.end());
  n = 2;
  result = generateParenthesis(n);
  ASSERT_EQ(result.size(), 2);
  ASSERT_TRUE(std::find(result.begin(), result.end(), "()()") != result.end());
  ASSERT_TRUE(std::find(result.begin(), result.end(), "(())") != result.end());
  n = 3;
  result = generateParenthesis(n);
  ASSERT_EQ(result.size(), 5);
  ASSERT_TRUE(std::find(result.begin(), result.end(), "()()()") !=
              result.end());
  ASSERT_TRUE(std::find(result.begin(), result.end(), "(())()") !=
              result.end());
  ASSERT_TRUE(std::find(result.begin(), result.end(), "()(())") !=
              result.end());
  ASSERT_TRUE(std::find(result.begin(), result.end(), "((()))") !=
              result.end());
  ASSERT_TRUE(std::find(result.begin(), result.end(), "(()())") !=
              result.end());
}
