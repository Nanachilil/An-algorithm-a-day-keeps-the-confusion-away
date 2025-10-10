// Copyright 2025 Nana Zhao

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

class Solution1 {
   public:
    std::vector<int>& nums;
    explicit Solution1(std::vector<int>& input) : nums(input) {}
    virtual ~Solution1() = default;
    std::vector<int>& GetIncreasedArray() {
        int nums_len = nums.size();

        for (int i = 0; i < nums_len; ++i) {
            nums[i] = nums[i] * nums[i];
        }

        // 使用快速排序对数组进行排序
        // 不使用标准库的排序函数
        QuickSort(0, nums_len - 1);
        // std::sort(nums.begin(), nums.end());

        return nums;
    }

   private:
    void QuickSort(int left, int right) {
        if (left >= right) {
            return;
        }
        int pivot = nums[left];
        int i = left;
        int j = right;
        while (i < j) {
            while (i < j && nums[j] >= pivot) {
                --j;
            }
            if (i < j) {
                nums[i] = nums[j];
                ++i;
            }
            while (i < j && nums[i] <= pivot) {
                ++i;
            }
            if (i < j) {
                nums[j] = nums[i];
                --j;
            }
        }
        nums[i] = pivot;
        QuickSort(left, i - 1);
        QuickSort(i + 1, right);
    }
};

// 使用双指针法
class Solution2 {
   public:
    std::vector<int>& nums;
    explicit Solution2(std::vector<int>& input) : nums(input) {}
    virtual ~Solution2() = default;

    std::vector<int>& GetIncreasedArray() {
        int nums_len = nums.size();
        std::vector<int> result_nums;
        int left = 0, right = nums_len - 1;
        while (left <= right) {
            if (abs(nums[left]) < abs(nums[right])) {
                result_nums.emplace_back(nums[right] * nums[right]);
                // emplace_back 是 vector中的成员函数
                --right;
            } else {
                result_nums.emplace_back(nums[left] * nums[left]);
                ++left;
            }
        }
        std::reverse(result_nums.begin(), result_nums.end());
        nums = result_nums;
        return nums;
    }
};

int main() {
    std::vector<int> nums = {-4, -3, 0, 1, 2};
    // Solution1 solution1(nums);
    // solution1.GetIncreasedArray();
    Solution2 solution2(nums);
    solution2.GetIncreasedArray();

    for (auto& num : nums) {
        std::cout << num << " ";
    }

    std::cout << std::endl;

    return 0;
}
