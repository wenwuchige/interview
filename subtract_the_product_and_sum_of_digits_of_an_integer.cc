// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
#include <iostream>
#include <vector>
using namespace std;
void getDigitalNum(int n, vector<char> *digitals) {
  while (n != 0) {
    digitals->push_back(n % 10);
    n /= 10;
  }
}

int subtractProductAndSum(int n) {
  std::vector<char> digitals;
  getDigitalNum(n, &digitals);
  int product = 1;
  int sum = 0;
  for (size_t n = 0; n < digitals.size(); ++n) {
    product *= digitals[n];
    sum += digitals[n];
  }
  return product - sum;
}
int main() {
  int n;
  cin >> n;
  std::cout << "the result is: " << subtractProductAndSum(n) << std::endl;
  return 0;
}
