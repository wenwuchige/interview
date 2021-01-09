// https://leetcode.com/problems/generate-parentheses/
// 使用回溯法
// 1.回溯终止条件,check 结果
// 2.for each 候选对象
//   执行回溯
//   恢复现场
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void trace_back(int left, int right, int total, int &stack,
                string *one_solution, vector<string> *result) {
  // 回溯终止条件, 找到一个可行解
  if (one_solution->length() == total) {
    result->push_back(*one_solution);
    return;
  }

  if (stack == 0) { //只能放左括号
    one_solution->push_back('(');
    stack++;
    --left;
    trace_back(left, right, total, stack, one_solution, result);
    // 恢复执行前状态
    stack--;
    ++left;
    one_solution->pop_back();
    return;
  }
  if (left == 0) {    // 无左括号可用
    if (right == 0) { // 无右括号可用
      return;
    }
    one_solution->push_back(')');
    stack--;
    --right;
    trace_back(left, right, total, stack, one_solution, result);
    // 恢复执行前状态
    stack++;
    ++right;
    one_solution->pop_back();
    return;
  }
  //左右都还有
  one_solution->push_back('(');
  stack++;
  --left;
  trace_back(left, right, total, stack, one_solution, result);
  // 恢复执行前状态
  stack--;
  ++left;
  one_solution->pop_back();
  one_solution->push_back(')');
  stack--;
  --right;
  trace_back(left, right, total, stack, one_solution, result);
  stack++;
  right++;
  one_solution->pop_back();
}

vector<string> generateParenthesis(int n) {
  vector<string> result;
  if (n == 0) {
    return result;
  }
  int stack = 0;
  string one_solution;
  trace_back(n, n, 2 * n, stack, &one_solution, &result);
  return result;
}
