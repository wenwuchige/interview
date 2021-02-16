// https://leetcode.com/problems/find-all-anagrams-in-a-string/
// 滑动窗口找到字符串的排列
#include <map>
#include <string>
#include <vector>
using namespace std;

vector<int> findAnagrams(string s, string p) {
  map<char, int> needed, window;
  for (auto &c : p) {
    needed[c]++;
  }
  // valid是已经满足条件的字符的个数,当他等于needed的长度时，就找到了一个可行解
  int valid = 0;
  int left = 0;
  int right = 0;
  vector<int> result;
  while (right < s.size()) {
    char c = s[right++];
    if (needed.count(c)) {
      window[c]++;
      if (window[c] == needed[c]) { //一个字符已经满足条件
        valid++;
      }
    }
    while (right - left >= p.size()) {
      if (valid == needed.size()) {
        result.push_back(left);
      }
      char d = s[left++];
      if (needed.count(d)) {
        if (window[d] ==
            needed[d]) { // 此时还满足条件，left变大后就不满足条件了
          valid--;
        }
        window[d]--;
      }
    }
  }
  return result;
}
