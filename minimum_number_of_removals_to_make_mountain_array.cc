#include <iostream>
#include <vector>
using namespace std;
// sort the nums to make it in increase order to get s2
// then calculate the lcss of s1 and s2 can get the longest non decrease sub
// sequency
// longest commmon sub sequency of s1 and s2
int longestCommmonSubSequency(const vector<int> &n1, const vector<int> &n2) {
  int length1 = n1.size();
  int length2 = n2.size();
  if (length1 == 0 || length2 == 0) {
    return 0;
  }
  // lcs[i,j] means the result of s1[0:i-1] and s2[0:j-1],which is a sub problem
  // of origin problem lcs[length1,length2]

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
      if (n1[i] == n2[j]) {
        lcs[i][j] = 1 + lcs[i - 1][j - 1];
      } else {
        lcs[i][j] = std::max(lcs[i - 1][j], lcs[i][j - 1]);
      }
    }
  }
  return lcs[length1][length2];
}

int minimumMountainRemovals(vector<int> &nums) { return 0; }

int main() {
  vector<int> nums;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    nums.push_back(num);
  }
  std::cout << "最小移除元素个数：" << minimumMountainRemovals(nums)
            << std::endl;
  return 0;
}
