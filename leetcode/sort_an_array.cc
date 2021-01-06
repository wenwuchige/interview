#include <iostream>
#include <vector>
using namespace std;
//-------------------insertion sort------------------------------------
size_t findInsertPos(vector<int> &nums, int target) {
  if (nums.empty()) {
    return 0;
  }
  if (target >= nums[nums.size() - 1]) {
    return nums.size();
  }
  if (target <= nums[0]) {
    return 0;
  }

  int left = 0;
  int right = int(nums.size() - 1);
  while (left <= right) {
    size_t mid = (left + right) / 2;
    if (nums[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  if (nums[right] > target) {
    return right - 1;
  }
  return right + 1;
}

vector<int> InsertSort(vector<int> &nums) {
  vector<int> result;
  if (nums.size() == 0) {
    return result;
  }
  for (size_t i = 0; i < nums.size(); ++i) {
    auto insert_pos = findInsertPos(result, nums[i]);
    result.insert(result.begin() + insert_pos, nums[i]);
    for (auto one : result) {
      std::cout << one << ",";
    }
    std::cout << endl;
  }
  return result;
}
//-------------------insertion sort------------------------------------
//-------------------quick sort------------------------------------
int partition(vector<int> &nums, int begin, int end) {
  int pivot = nums[begin];
  int tmp = end;
  swap(nums[begin], nums[end]);
  --end;
  while (begin <= end) {
    if (nums[end] < pivot) {
      std::swap(nums[begin++], nums[end]);
      continue;
    }
    if (nums[begin] > pivot) {
      std::swap(nums[begin], nums[end--]);
      continue;
    }
    begin++;
    end--;
  }
  swap(nums[begin], nums[tmp]);
  return begin;
}

void doQuickSort(vector<int> &nums, int begin, int end) {
  if (begin >= end) {
    return;
  }
  int pivot = partition(nums, begin, end);
  doQuickSort(nums, begin, pivot - 1);
  doQuickSort(nums, pivot + 1, end);
}

vector<int> QuickSort(vector<int> &nums) {
  doQuickSort(nums, 0, nums.size() - 1);
  return nums;
}
//-------------------quick sort------------------------------------
vector<int> sortArray(vector<int> &nums) {
  std::vector<int> result;
  return result;
}

int main() {
  std::vector<int> input = {-4, 0, 7, 4, 9, -5, -1, 0, -7, -1};
  // auto result = InsertSort(input);
  auto result = QuickSort(input);
  for (size_t i = 0; i < result.size(); ++i) {
    std::cout << result[i] << " ,";
  }
  return 0;
}
