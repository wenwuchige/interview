// https://leetcode-cn.com/problems/add-two-numbers/
// 先将链表反转，分别得到其低位，然后相加
// 相加的时候注意current = current->next;
// 如果current->next是nullptr，那么current其实会变成nulptr，它原先的内存也会泄漏
#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}

  void print() {
    std::cout << "val:" << val << std::endl;
    ListNode *root = next;
    while (root != nullptr) {
      std::cout << "val:" << root->val << std::endl;
      root = root->next;
    }
  }
};

ListNode *reverse(ListNode *head) {
  if (head == nullptr) {
    return nullptr;
  }
  ListNode *pre = nullptr;
  ListNode *current = head;
  ListNode *next = head->next;
  while (next != nullptr) {
    current->next = pre;
    pre = current;
    current = next;
    next = current->next;
  }
  current->next = pre;
  return current;
}

void addList(ListNode *&l1, ListNode *l2, int bit) {
  if (l2 == nullptr && bit != 0) {
    std::cout << "最高位：" << bit << std::endl;
    l1->next = new ListNode(bit);
    return;
  }

  while (l2 != nullptr) {
    int this_sum = (l2->val + bit) % 10;
    std::cout << "add this_sum: " << this_sum << std::endl;
    bit = (l2->val + bit) / 10;
    l1->next = new ListNode(this_sum);
    l1 = l1->next;
    l2 = l2->next;
  }
  if (bit != 0) {
    l1->next = new ListNode(bit);
  }
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  if (l1 == nullptr && l2 == nullptr) {
    return nullptr;
  }
  // auto r1 = reverse(l1);
  // auto r2 = reverse(l2);
  auto r1 = l1;
  auto r2 = l2;
  int bit = 0;
  ListNode *head = nullptr;
  ListNode *current = nullptr;
  while (r1 != nullptr && r2 != nullptr) {
    int this_sum = (r1->val + r2->val + bit) % 10;
    std::cout << "this sum:" << this_sum << std::endl;
    bit = (r1->val + r2->val + bit) / 10;
    std::cout << "bit: " << bit << std::endl;
    if (head == nullptr) {
      head = new ListNode(this_sum);
      current = head;
    } else {
      current->next = new ListNode(this_sum);
      current = current->next;
    }
    r1 = r1->next;
    r2 = r2->next;
  }

  if (r1 != nullptr) {
    addList(current, r1, bit);
  } else {
    addList(current, r2, bit);
  }
  return (head);
}
