#include "leetcode/back_track/n_queens.cc"
#include "third_party/gtest/include/gtest.h"
#include <iostream>
using namespace std;

TEST(tmp, solveNQueens) {
  int n = 3;
  auto result = solveNQueens(n);
  for (int i = 0; i < result.size(); i++) {
    std::cout << "result " << i << std::endl;
    for (int j = 0; j < n; ++j) {
      std::cout << result[i][j] << std::endl;
    }
    std::cout << std::endl;
  }
}
