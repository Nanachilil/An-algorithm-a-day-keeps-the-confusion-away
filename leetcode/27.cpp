#include <cstdint>
#include <iostream>
#include <vector>

class Solution
{
  public:
    std::vector<int> &nums;

    Solution(std::vector<int> &nums) : nums(nums)
    {
    }
    virtual ~Solution() = default;
    int RemoveElement(int val)
    {
        int nums_len = 0; // 记录不等于 val 的元素个数
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != val)
            {
                nums[nums_len] = nums[i]; // 将不等于 val 的元素移动到前面
                ++nums_len;
            }
        }
        return nums_len;
    }
};

inline int ReadInt()
{
    int
}

int main()
{
    std::vector<int> nums;
    int val;

    Solution solution(nums);

    int new_length = solution.RemoveElement(nums, val);
    std::cout << "New length: " << new_length << std::endl;
    std::cout << "Modified array: ";
    for (int i = 0; i < new_length; ++i)
    {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
