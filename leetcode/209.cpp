// Copyright (c) 2025-10-09 Nana

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

class Solution1 {
   public:
    std::vector<int>& nums;
    explicit Solution1(std::vector<int>& input) : nums(input) {}
    virtual ~Solution1() = default;
    int MinSubArrayLen(int target) {
        int n = nums.size();
        int left = 0, right = 0;
        int sum = 0;
        int min_length = INT32_MAX;

        while (right < n) {
            sum += nums[right];
            while (sum >= target) {
                min_length = std::min(min_length, right - left + 1);
                sum -= nums[left];
                ++left;
            }
            ++right;
        }
        return min_length == INT32_MAX ? 0 : min_length;
    }
};

int main() {
    std::vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    Solution1 solution(nums);

    int min_length = solution.MinSubArrayLen(target);
    std::cout << "Min length: " << min_length << std::endl;
    return 0;
}
