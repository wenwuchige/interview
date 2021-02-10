#include "leetcode/binary_tree/preorder_inorder_rebuild_binary_tree.cc"
#include "third_party/gtest/include/gtest.h"

TEST(tmp, buildTree) {
  std::vector<int> preorder = {3, 9, 20, 15, 7};
  std::vector<int> inorder = {9, 3, 15, 20, 7};
  TreeNode *root = buildTree(preorder, inorder);
  ASSERT_TRUE(root != nullptr);
  EXPECT_EQ(root->val, 3);
  EXPECT_EQ(root->left->val, 9);
  EXPECT_EQ(root->right->val, 20);
  EXPECT_EQ(root->right->left->val, 15);
  EXPECT_EQ(root->right->right->val, 7);
}
