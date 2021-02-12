// https://leetcode.com/problems/n-queens/
// 使用回溯算法穷举
// 其实还有个优化的小技巧，判断对角线是否有皇后时，上对角线的行列之和为常数，下对角线的行列之差为常数
#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<vector<string>> result;
vector<vector<bool>> flags;
vector<string> tmp;

string putQueue(int n, int i) {
  string result(n, '.');
  result[i] = 'Q';
  return result;
}

bool canPut(int N, int row_index, int col_index) {
  for (int i = 0; i < N; i++) { // 检查同行有没有皇后,应该可以略过去
    if (flags[row_index][i]) {
      return false;
    }
  }
  for (int i = 0; i < N; i++) { //检查同列有没有皇后
    if (flags[i][col_index]) {
      return false;
    }
  }
  //检查对角线上有没有皇后
  int k = 1;
  // while (true) {
  //   int left_up_row = row_index - k;
  //   int left_up_col = col_index - k;
  //   if (left_up_row < 0 || left_up_col < 0) {
  //     break;
  //   }
  //   if (flags[left_up_row][left_up_col]) {
  //     return false;
  //   }
  //   k++;
  // }
  while (true) {
    int right_down_row = row_index + k;
    int right_down_col = col_index + k;
    if (right_down_row == N || right_down_col == N) {
      break;
    }
    if (flags[right_down_row][right_down_col]) {
      return false;
    }
    k++;
  }
  k = 1;
  while (true) {
    int left_down_row = row_index + k;
    int left_down_col = col_index - k;
    if (left_down_row == N || left_down_col < 0) {
      break;
    }
    if (flags[left_down_row][left_down_col]) {
      return false;
    }
    k++;
  }
  // k = 1;
  // while (true) {
  //   int right_up_row = row_index - k;
  //   int right_up_col = row_index + k;
  //   if (right_up_row < 0 || right_up_col == N) {
  //     break;
  //   }
  //   if (flags[right_up_row][right_up_col]) {
  //     return false;
  //   }
  //   k++;
  // }
  return true;
}

void backtrack(int N, int n, vector<vector<bool>> &flags) {
  // one step 找到一个解,记录这个解
  if (n == 0) { // 找到了可行解
    result.push_back(tmp);
    return;
  }
  // one step 可能做的选择
  for (int i = 0; i < N; i++) { // 有n个地方可以放皇后
    if (!canPut(N, n - 1, i)) { // one step 可能有的约束条件，进行减支
      // std::cout << "can't put here " << n - 1 << i << std::endl;
      continue;
    }
    // one step 做选择 然后回溯
    flags[n - 1][i] = true;
    string one_row = putQueue(N, i);
    tmp.push_back(one_row);
    backtrack(n, n - 1, flags);
    // one step 还原
    flags[N - 1][i] = false;
    tmp.pop_back();
  }
}

vector<vector<string>> solveNQueens(int n) {
  flags.resize(n);
  for (int i = 0; i < n; i++) {
    flags[i].resize(n);
    for (int j = 0; j < n; ++j) {
      flags[i][j] = false;
    }
  }
  backtrack(n, n, flags);
  return result;
}
