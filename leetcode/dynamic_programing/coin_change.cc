// https://leetcode.com/problems/coin-change/submissions/
// 动态规划问题，愿问题的解等于子问题的最小值+1
// 状态转移方程dp[amount] = 1 + min(sub_problem)
// sub_problem 可以使用备忘录来记录

#include <map>
#include <vector>
using namespace std;

std::map<int, int> memo;

int dp(vector<int> &coins, int amount) {
  if (amount == 0) {
    return 0;
  }

  if (amount < 0) {
    return -1;
  }

  int ans = INT_MAX;
  bool has_solved = false;
  for (int i = 0; i < coins.size(); ++i) {
    int sub_problem = -1;
    if (memo.find(amount - coins[i]) != memo.end()) {
      sub_problem = memo[amount - coins[i]];
    } else {
      sub_problem = dp(coins, amount - coins[i]);
    }
    if (sub_problem != -1) {
      ans = std::min(ans, sub_problem + 1);
      has_solved = true;
    }
  }
  if (!has_solved) {
    memo[amount] = -1; // 没有解也要记录下来
    return -1;
  }
  memo[amount] = ans;
  return ans;
}

int coinChange(vector<int> &coins, int amount) {
  memo.clear();
  return dp(coins, amount);
}
