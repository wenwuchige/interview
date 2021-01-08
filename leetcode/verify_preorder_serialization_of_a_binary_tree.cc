// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
// a node need two sub node which can be # or normal node
// the root node need 2 sub mode
// for each normal node which become a sub node and need two more sub node
// for a # node which can only become a sub node
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
bool isValidSerialization(string preorder) {
  if (preorder.length() == 1) {
    return preorder == "#";
  }
  stringstream ss(preorder);
  std::string tmp;
  int base = 0;
  int root = 0;
  bool end = false;
  while (getline(ss, tmp, ',')) {
    if (end) {
      return false;
    }
    if (root == 0) {
      if (tmp == "#") {
        return false;
      }
      base += 2;
      root++;
      continue;
    }
    if (tmp != "#") {
      base += 1;
    } else {
      base -= 1;
    }
    if (base < 0) {
      return false;
    }
    if (base == 0) {
      end = true;
    }
  }
  return base == 0;
}
