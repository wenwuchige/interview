// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// 使用滑动窗口来判断
#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
  if (s.empty()) {
    return 0;
  }

  int result = 1;
  int left = 0, right = 0;
  unordered_map<char, int> window;
  int valid = 0; //窗口中重复的字符个数

  while (right < s.length()) {
    char r_c = s[right++];
    // 加入到窗口需要的更新
    if (window[r_c] != 0) {
      valid++;
    }
    window[r_c]++;
    std::cout << "left: " << left << " right: " << right - 1
              << " valid: " << valid << std::endl;
    if (valid == 0) {
      result = std::max(result, right - left);
    }
    while (right - left > 1 && valid >= 0) { // 缩小窗口的条件
      if (valid == 0) {
        result = std::max(result, right - left);
        break;
      }
      // 减少窗口
      char l_c = s[left++];
      --window[l_c];
      if (window[l_c] == 1) { // 只剩下一个时候是没有重复
        valid--;
      }
      std::cout << "left: " << left << " right: " << right - 1
                << " valid: " << valid << std::endl;
    }
  }
  return result;
}
