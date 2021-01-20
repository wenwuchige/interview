#include "leetcode/list/add_two_numbers.cc"
#include "third_party/gtest/include/gtest.h"
class AddTwoNumbers : public ::testing::Test {
public:
  void SetUp() override {
    l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    l3 = new ListNode(0);
    l4 = new ListNode(0);

    l5 = new ListNode(9);
    auto tmp = l5;
    for (int i = 0; i < 6; ++i) {
      tmp->next = new ListNode(9);
      tmp = tmp->next;
    }
    l6 = new ListNode(9);
    tmp = l6;
    for (int i = 0; i < 3; ++i) {
      tmp->next = new ListNode(9);
      tmp = tmp->next;
    }
  }

  void TearDown() override {
    DeleteList(l1);
    DeleteList(l2);
    DeleteList(l3);
    DeleteList(l4);
    DeleteList(l5);
    DeleteList(l6);
  }

  ListNode *l1 = nullptr;
  ListNode *l2 = nullptr;
  ListNode *l3 = nullptr;
  ListNode *l4 = nullptr;
  ListNode *l5 = nullptr;
  ListNode *l6 = nullptr;

private:
  void DeleteList(ListNode *head) {
    if (head == nullptr) {
      return;
    }
    DeleteList(head->next);
    delete head;
  }
};

TEST_F(AddTwoNumbers, reverse) {
  ListNode *l1_reverse = reverse(l1);
  ListNode *l2_reverse = reverse(l2);
  ASSERT_EQ(l1_reverse->val, 3);
  ASSERT_EQ(l1_reverse->next->val, 4);
  ASSERT_EQ(l1_reverse->next->next->val, 2);
  ASSERT_EQ(l2_reverse->val, 4);
  ASSERT_EQ(l2_reverse->next->val, 6);
  ASSERT_EQ(l2_reverse->next->next->val, 5);
}

TEST_F(AddTwoNumbers, addTwoNumbers) {
  ListNode *result1 = addTwoNumbers(l1, l2);
  result1->print();
  ListNode *result2 = addTwoNumbers(l3, l4);
  result2->print();
  l5->print();
  l6->print();
  ListNode *result3 = addTwoNumbers(l5, l6);
  result3->print();
}
