#include <iostream>
#include <map>
#include <vector>

using namespace std;
bool isPalindromic(const std::string &s,
                   const std::vector<std::vector<bool>> &flag, size_t begin,
                   size_t end) {
  if (begin == end) {
    return true;
  }
  if (s[begin] != s[end]) {
    return false;
  }
  if (end == begin + 1) {
    return true;
  }
  return flag[begin + 1][end - 1];
}

int countSubstrings(string s) {
  if (s.length() == 0) {
    return 0;
  }
  std::map<char, std::vector<size_t>> value_map;
  // if s[i,j] is palindromic flag[i][j] == true, otherwise false
  std::vector<std::vector<bool>> flag;
  flag.resize(s.length());
  for (size_t i = 0; i < s.length(); ++i) {
    flag[i].resize(s.length(), false);
    flag[i][i] = true;
  }
  std::vector<int> result;
  result.resize(s.length());
  result[0] = 1;
  value_map.emplace(s[0], std::vector<size_t>(1, 0));
  for (size_t i = 1; i < s.length(); ++i) {
    result[i] = result[i - 1] + 1;
    auto iter = value_map.find(s[i]);
    if (iter == value_map.end()) {
      value_map.emplace(s[i], std::vector<size_t>(1, i));
      continue;
    }
    for (auto &index : iter->second) {
      bool is_palindormic = isPalindromic(s, flag, index, i);
      if (is_palindormic) {
        result[i]++;
        flag[index][i] = true;
      }
    }
    iter->second.push_back(i);
  }
  return result[s.length() - 1];
}
int main() {
  std::string s;
  cin >> s;
  int result = countSubstrings(s);
  std::cout << "palindromic num is: " << result << std::endl;
  return 0;
}
