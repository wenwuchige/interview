// https://leetcode.com/problems/minimum-depth-of-binary-tree/
// 使用bfs算法，第一个找到的叶子节点就是最小深度所在的节点

#include <queue>
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

int minDepth(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }
  queue<TreeNode *> queue;
  int depth = 1;
  queue.push(root);
  while (!queue.empty()) {
    int size = queue.size();
    for (int i = 0; i < size; i++) {
      auto node = queue.front();
      if (node->left == nullptr && node->right == nullptr) {
        return depth;
      }
      queue.pop();
      if (node->left) {
        queue.push(node->left);
      }
      if (node->right) {
        queue.push(node->right);
      }
    }
    depth++;
  }
  return depth;
}
