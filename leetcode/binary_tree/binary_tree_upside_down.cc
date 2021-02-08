struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

TreeNode *upsideDownBinaryTree(TreeNode *root) {
  if (root == nullptr) {
    return nullptr;
  }
  // step 1 root to right
  return new_root;
}
