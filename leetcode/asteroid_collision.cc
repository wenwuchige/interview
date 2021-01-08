// https://leetcode.com/problems/asteroid-collision
// using stack
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids) {
  std::vector<int> result;
  if (asteroids.size() == 0) {
    return result;
  }
  stack<int> left_stack;
  stack<int> right_stack;
  for (size_t i = 0; i < asteroids.size(); ++i) {
    if (asteroids[i] > 0) {
      right_stack.push(asteroids[i]);
      continue;
    }
    if (right_stack.empty()) {
      result.push_back(asteroids[i]);
      continue;
    }
    bool left_exploid = false;
    int abs = 0 - asteroids[i];
    while (!right_stack.empty()) {
      auto top = right_stack.top();
      if (top > abs) {
        left_exploid = true;
        break;
      }
      if (top == abs) {
        left_exploid = true;
        right_stack.pop();
        break;
      }
      right_stack.pop();
    }
    if (!left_exploid) {
      result.push_back(asteroids[i]);
    }
  }
  std::stack<int> tmp;
  while (!right_stack.empty()) {
    tmp.push(right_stack.top());
    right_stack.pop();
  }
  while (!tmp.empty()) {
    result.push_back(tmp.top());
    tmp.pop();
  }
  return result;
}

int main() {
  std::string input;
  char comma;
  cin >> input;
  stringstream ss(input);
  vector<int> asteroids;
  while (ss) {
    int num;
    ss >> num;
    ss >> comma;
    asteroids.push_back(num);
  }
  std::cout << "input is: ";
  for (size_t i = 0; i < asteroids.size(); ++i) {
    std::cout << asteroids[i] << ",";
  }
  std::cout << std::endl;
  auto result = asteroidCollision(asteroids);
  std::cout << "result is: ";
  for (size_t i = 0; i < result.size(); ++i) {
    std::cout << result[i] << ",";
  }
  return 0;
}
