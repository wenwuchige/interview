// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// 根据前序和中序还原二叉树
// 前序中第一个节点是根节点，然后用它将中序分割为左右两部分，左边是左子树的中序，右边是右子树的中序
// build 方法的index要仔细计算，有个约束条件即中序遍历和前序遍历的长度应该一致
// 有个约束限制，即数组中不能有重复元素
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

TreeNode *build(vector<int> &preorder, int pre_begin, int pre_end,
                vector<int> &inorder, int in_begin, int in_end) {
  if (pre_begin > pre_end || in_begin > in_end || pre_begin < 0 ||
      pre_end >= preorder.size() || in_begin < 0 || in_end >= inorder.size()) {
    return nullptr;
  }
  int root_value = preorder[pre_begin];
  TreeNode *root = new TreeNode(root_value);
  int left_child_num = 0;
  for (int i = in_begin; i <= in_end; ++i) {
    if (inorder[i] == root_value) { //找到了跟节点
      root->left = build(preorder, pre_begin + 1, pre_begin + left_child_num,
                         inorder, in_begin, in_begin + left_child_num - 1);
      root->right = build(preorder, pre_begin + left_child_num + 1, pre_end,
                          inorder, in_begin + left_child_num + 1, in_end);
      break; //因为没有重复元素，所以不break也是可以的，不过会多循环
    }
    ++left_child_num;
  }
  return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
  if (preorder.size() == 0 || inorder.size() == 0) {
    return nullptr;
  }
  return build(preorder, 0, preorder.size() - 1, inorder, 0,
               inorder.size() - 1);
}
