#include "leetcode/binary_tree/binary_tree_maximum_path_sum.cc"
#include "third_party/gtest/include/gtest.h"

TEST(testTmp, maxPathSum) {
  TreeNode *root = new TreeNode(-3);
  ASSERT_EQ(maxPathSum(root), -3);
  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->right = new TreeNode(3);
  ASSERT_EQ(maxPathSum(root1), 6);
  TreeNode *root2 = new TreeNode(-10);
  root2->left = new TreeNode(9);
  root2->right = new TreeNode(20);
  root2->right->left = new TreeNode(15);
  root2->right->right = new TreeNode(7);
  ASSERT_EQ(maxPathSum(root2), 42);
}
