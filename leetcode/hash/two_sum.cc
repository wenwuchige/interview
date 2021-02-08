#include <vector>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target) {
  vector<int> result;
  map<int, int> value_index;
  for (int i = 0; i < nums.size(); ++i) {
    value_index[target - nums[i]] = i;
  }
  for (int i = 0; i < nums.size(); ++i) {
    if (value_index.find(nums[i]) != value_index.end() &&
        i != value_index[nums[i]]) {
      result.push_back(i);
      result.push_back(value_index[nums[i]]);
      break;
    }
  }
  return result;
}
