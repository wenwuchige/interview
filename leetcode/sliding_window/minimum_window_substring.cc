// https://leetcode.com/problems/minimum-window-substring/
// 滑动窗口算法
// 1.定义目标
// 2.增大窗口，寻找可行解
// 3.缩小窗口，优化可行解, 在缩小的时候更新最优解

#include <iostream>
#include <map>
#include <string>

using namespace std;
bool valid(const map<char, int> &needed, const string &t) {
  for (const auto &one : t) {
    if (needed.find(one) == needed.end()) {
      return false;
    } else {
      if (needed.at(one) > 0) {
        return false;
      }
    }
  }
  return true;
}

string minWindow(string s, string t) {
  int left = 0;
  int right = 0;
  string result = "";
  map<char, int> needed;
  int need_length = t.size();
  // 初始化needed map中保存需要的字符
  for (auto one_letter : t) {
    needed[one_letter]++;
  }

  while (right < s.length()) {
    char right_char = s[right++]; // 扩大窗口
    if (needed.find(right_char) == needed.end()) {
      continue;
    }
    needed[right_char]--;
    if (needed[right_char] >= 0) {
      need_length--;
    }

    while (need_length == 0) { // 缩小窗口
      int window_size = right - left;
      // std::cout << "window size is :" << window_size << std::endl;
      // 更新结果
      if (result == "") {
        result = string(s, left, window_size);
      } else if (result.length() > window_size) {
        result = string(s, left, window_size);
      }
      char left_char = s[left++];
      if (needed.find(left_char) == needed.end()) {
        continue;
      }
      needed[left_char]++;
      if (needed[left_char] > 0) {
        need_length++;
      }
    }
  }
  return result;
}
