#include "leetcode/verify_preorder_serialization_of_a_binary_tree.cc"
#include "third_party/gtest/include/gtest.h"
#include <vector>

TEST(Veryfy, isValidSerialization) {
  std::string s = "9,3,4,#,#,1,#,#,2,#,6,#,#";
  EXPECT_TRUE(isValidSerialization(s));
  s = "1,#";
  EXPECT_FALSE(isValidSerialization(s));
  s = "9,#,#,1";
  EXPECT_FALSE(isValidSerialization(s));
  s = "7,2,#,2,#,#,#,6,#";
  EXPECT_FALSE(isValidSerialization(s));
}
