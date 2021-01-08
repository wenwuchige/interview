// Copyright [2020] <Copyright zyc>
// Author zyc2010303268@163.com(zyc)
// description:
// https://leetcode.com/problems/minimum-swaps-to-make-strings-equal
// there are (x,x), (x,y), (y,x) (y,y) pairs
// (x,x) and (y,y) needn't operation
// one swap can make (x,y) and (x,y) to the same string, which also apply to
// (y,x) and (y,x) pair, while two swaps can make (x,y) and (y,x) to the same
// string

#include <iostream>
#include <string>
using namespace std;
int firstNotMatchIndex(const string &s1, const string &s2, char letter,
                       int index) {
  for (size_t i = index; i < s2.size(); ++i) {
    if (s1[i] == letter && s2[i] != letter) {
      return i;
    }
  }
  return -1;
}

void swap(char &c1, char &c2) {
  char tmp = c1;
  c1 = c2;
  c2 = tmp;
}

int minimumSwap(string s1, string s2) {
  if (s1.size() != s2.size()) {
    return -1;
  }
  int minimum = 0;
  for (size_t i = 0; i < s1.size(); ++i) {
    if (s1[i] == s2[i]) {
      continue;
    }
    int index = firstNotMatchIndex(s1, s2, s1[i], i + 1);
    if (index == -1) {
      if (i == s1.size() - 1) {
        return -1;
      }
      swap(s1[i], s2[i]);
      ++minimum;
      int sub = minimumSwap(s1, s2);
      if (sub == -1) {
        return -1;
      }
      return minimum + sub;
    }
    swap(s1[i], s2[index]);
    ++minimum;
  }
  return minimum;
}
