#include "leetcode/bfs/open_the_lock.cc"
#include "third_party/gtest/include/gtest.h"

TEST(openLockTest, openLock) {
  std::vector<std::string> depends = {"0201", "0101", "0102", "1212", "2002"};
  std::string target = "0202";
  EXPECT_EQ(openLock(depends, target), 6);
  depends.clear();
  depends = {"8888"};
  target = "0009";
  EXPECT_EQ(openLock(depends, target), 1);
  depends.clear();
  depends = {"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"};
  target = "8888";
  EXPECT_EQ(openLock(depends, target), -1);
  depends.clear();
  depends = {"0000"};
  target = "8888";
  EXPECT_EQ(openLock(depends, target), -1);
}
