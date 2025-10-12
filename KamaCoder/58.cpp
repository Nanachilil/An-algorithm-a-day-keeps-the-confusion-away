// Copyright (c) 2025-10-11 Nana Zhao

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

#define MAX_NUM 1000

class Solution {
   public:
    int& array_len;
    std::vector<int>& array;
    Solution(int& array_len, std::vector<int>& array) : array_len(array_len), array(array) {}
    virtual ~Solution() = default;

    int SumOfAreaInArray(int left, int right) {
        int sum = 0;
        for (int i = left; i <= right; ++i) {
            sum += array[i];
        }
        return sum;
    }

    std::vector<int> SumOfArrayInArray() {
        std::vector<int> sum_array(array_len, 0);
        sum_array[0] = array[0];
        for (int i = 1; i < array_len; ++i) {
            sum_array[i] = sum_array[i - 1] + array[i];
        }
        return sum_array;
    }
};

int main() {
    int array_len = getchar() - '0';
    // std::cout << "Input array length is: " << array_len << std::endl;
    std::vector<int> array(array_len, MAX_NUM);
    std::vector<int> sum_array(array_len, 0);
    int left = 0, right = 0;

    for (int i = 0; i < array_len; ++i) {
        int num = 0, sign = 1;
        char ch = getchar();
        while ((ch < '0' || ch > '9') && ch != '-') {
            ch = getchar();
        }
        // 处理负号
        if (ch == '-') {
            sign = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9') {
            num = num * 10 + (ch - '0');
            ch = getchar();
        }
        array[i] = num * sign;
    }

    Solution solution(array_len, array);
    sum_array = solution.SumOfArrayInArray();
    while (std::cin >> left >> right) {
        std::cout << sum_array[right] - (left > 0 ? sum_array[left - 1] : 0) << std::endl;
    }

    return 0;
}
