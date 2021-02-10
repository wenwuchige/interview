// https://leetcode.com/problems/binary-tree-maximum-path-sum/
// 最大路径的可能情况
// 1.单纯的以root的左节点为根的子树里 （子问题1）
// 2.单纯的以root的右节点为根的子树里 （自问题2）
// 3.包含root到左子树的某个路径
// 4.包含root到右子树的某个路基
// 5.既包含左子树又包含右子树的某个路基
// 6.只包含根一个节点
//
#include <algorithm>
#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

int oneSideMax(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }
  int left = std::max(0, oneSideMax(root->left));
  int right = std::max(0, oneSideMax(root->right));
  return std::max(left, right) + root->val;
}

int maxPathSum(TreeNode *root) {
  if (root == nullptr) {
    return INT_MIN;
  }
  int left_max = maxPathSum(root->left); // case 1
  std::cout << "left_max:" << left_max << std::endl;
  int right_max = maxPathSum(root->right); // case 2
  std::cout << "right_max:" << right_max << std::endl;
  int left_side_max = oneSideMax(root->left); // case 3
  std::cout << "left_side_max:" << left_side_max << std::endl;
  int right_side_max = oneSideMax(root->right); // case 4
  std::cout << "right_side_max:" << right_side_max << std::endl;
  int contain_root_max = left_side_max + right_side_max + root->val; // case 5
  std::cout << "contain_root_max:" << contain_root_max << std::endl;
  int result = root->val;
  result = std::max(left_max, result);
  result = std::max(right_max, result);
  result = std::max(left_side_max + root->val, result);
  result = std::max(right_side_max + root->val, result);
  result = std::max(contain_root_max, result);

  return result;
}
