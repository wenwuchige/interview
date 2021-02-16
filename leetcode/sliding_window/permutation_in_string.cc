// https://leetcode.com/problems/permutation-in-string/
// 滑动窗口算法

#include <map>
#include <string>
using namespace std;

bool checkInclusion(string s1, string s2) {
  // 定义检查满足条件时需要的数据结构并初始化
  map<char, int> needed;
  for (auto &c : s1) {
    needed[c]++;
  }

  int left = 0, right = 0;
  int valid = 0;
  while (right < s2.size()) { // 扩大窗口
    char r_c = s2[right++];
    if (needed.find(r_c) == needed.end()) { // 无关的字符
      continue;
    }
    if (--needed[r_c] >= 0) {
      valid++;
      if ((right - left) == s1.size() && valid == s1.size()) { // 检查当前窗口
        return true;
      }
    }

    while ((right - left) >= s1.size()) { //减小窗口的条件
      if ((right - left) == s1.size() && valid == s1.size()) {
        return true;
      }
      char l_c = s2[left++];
      if (needed.find(l_c) == needed.end()) { //先判断
        continue;
      }
      if (++needed[l_c] > 0) {
        valid--;
      }
    }
  }
  return false;
}
