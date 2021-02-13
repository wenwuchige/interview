// https://leetcode.com/problems/open-the-lock/
// 广度优先变量，start - target 寻找最小值
// 每次有 2*n (n为秘密长度), 向上or向下播
//
//
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
static int result = 0;
set<string> already;

void putUp(string &now, int i) {
  if (now[i] == '9') {
    now[i] = '0';
  } else {
    now[i] += 1;
  }
}

void putDown(string &now, int i) {
  if (now[i] == '0') {
    now[i] = '9';
  } else {
    now[i] -= 1;
  }
}

void traceback(std::string &origin, const string &target,
               const set<string> &deadends) {
  if (origin == target) {
    return;
  }

  if (deadends.count(origin) != 0) {
    result = -1;
    return;
  }

  queue<string> queue;
  queue.push(origin); // 放入起始位置
  already.insert(origin);

  while (!queue.empty()) {
    int size = queue.size();
    for (int i = 0; i < size; i++) { // 遍历一层
      auto one_item = queue.front();
      if (one_item == target) { // 找到了，return
        return;
      }
      queue.pop();
      for (int j = 0; j < one_item.size(); j++) { //加入下一层元素
        putUp(one_item, j);
        if (deadends.count(one_item) == 0 && already.count(one_item) == 0) {
          queue.push(one_item);
          already.insert(one_item);
        }
        putDown(one_item, j);
        putDown(one_item, j);
        if (deadends.count(one_item) == 0 && already.count(one_item) == 0) {
          queue.push(one_item);
          already.insert(one_item);
        }
        putUp(one_item, j);
      }
    }
    result++;
  }
  result = -1; //遍历结束，没有找到可行解
}

int openLock(vector<string> &deadends, string target) {
  string origin = "0000";
  set<string> tmp_set(deadends.begin(), deadends.end());
  result = 0;
  already.clear();
  traceback(origin, target, tmp_set);
  return result;
}
