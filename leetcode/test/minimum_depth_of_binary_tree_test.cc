#include "leetcode/binary_tree/minimum_depth_of_binary_tree.cc"
#include "third_party/gtest/include/gtest.h"

TEST(tmp, minDepth) {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(20);
  EXPECT_EQ(minDepth(root), 2);

  TreeNode *root1 = new TreeNode(1);
  root1->right = new TreeNode(2);
  root1->right->right = new TreeNode(3);
  root1->right->right->right = new TreeNode(4);
  root1->right->right->right->right = new TreeNode(5);
  EXPECT_EQ(minDepth(root1), 5);
}
