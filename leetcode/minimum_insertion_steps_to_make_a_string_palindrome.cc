#include <iostream>
#include <vector>
using namespace std;
int longestCommonSubsequence(string text1, string text2) {
  int length1 = text1.size();
  int length2 = text2.size();
  if (length1 == 0 || length2 == 0) {
    return 0;
  }
  std::vector<std::vector<int>> lcs;
  lcs.resize(length1 + 1);
  for (int i = 0; i <= length1; ++i) {
    lcs[i].resize(length2 + 1);
  }
  for (int k = 0; k <= length2; ++k) {
    lcs[0][k] = 0;
  }
  for (int k = 0; k <= length1; ++k) {
    lcs[k][0] = 0;
  }
  for (int i = 1; i <= length1; ++i) {
    for (int j = 1; j <= length2; ++j) {
      if (text1[i - 1] == text2[j - 1]) {
        lcs[i][j] = 1 + lcs[i - 1][j - 1];
      } else {
        lcs[i][j] = std::max(lcs[i - 1][j], lcs[i][j - 1]);
      }
    }
  }
  return lcs[length1][length2];
}

int minInsertions(string s) {
  std::string tmp(s);
  std::reverse(tmp.begin(), tmp.end());
  return s.length() - longestCommonSubsequence(s, tmp);
}

int main() {
  std::string input;
  cin >> input;
  std::cout << "最少次数：" << minInsertions(input) << std::endl;
  return 0;
}
