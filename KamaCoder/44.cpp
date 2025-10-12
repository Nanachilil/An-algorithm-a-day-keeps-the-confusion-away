// Copyright (c) 2025-10-12 Nana Zhao

#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

#define MAX_NUM 111111111

class Solution {
   public:
    int& row;
    int& col;
    std::vector<std::vector<int>>& land_nums;
    Solution(std::vector<std::vector<int>>& input_land_nums, int& input_row, int& input_col)
        : land_nums(input_land_nums), row(input_row), col(input_col) {}
    virtual ~Solution() = default;
    int MinDiffInArray() {
        std::vector<int> sum_row(row, 0);
        std::vector<int> sum_col(col, 0);
        int sum_of_array;
        int min_diff = MAX_NUM;

        // 赋值 sum_row
        for (int i = 0, j = 0; i < row; ++i) {
            j = 0;
            for (; j < col; ++j) {
                sum_row[i] += land_nums[i][j];
            }
            if (i != 0) {
                sum_row[i] += sum_row[i - 1];
            }
        }

        // 赋值 sum_col
        for (int i = 0, j = 0; j < col; ++j) {
            i = 0;
            for (; i < row; ++i) {
                sum_col[j] += land_nums[i][j];
            }
            if (j != 0) {
                sum_col[j] += sum_col[j - 1];
            }
        }

        sum_of_array = sum_col[col - 1];

        // 取最小
        for (int i = 0; i < row - 1; ++i) {
            if (min_diff > std::abs((sum_of_array - sum_row[i] - sum_row[i])))
                min_diff = std::abs(sum_of_array - sum_row[i] - sum_row[i]);
        }
        for (int j = 0; j < col - 1; ++j) {
            if (min_diff > (std::abs(sum_of_array - sum_col[j] - sum_col[j])))
                min_diff = std::abs(sum_of_array - sum_col[j] - sum_col[j]);
        }
        return min_diff;
    }
};

int main() {
    int row, col;
    int min_diff;

    std::cin >> row >> col;
    std::vector<std::vector<int>> land_nums(row, std::vector<int>(col, MAX_NUM));

    int temp;
    for (int i = 0, j = 0; i < row; ++i) {
        j = 0;
        for (; j < col; ++j) {
            std::cin >> land_nums[i][j];
        }
    }

    // for (int i = 0, j = 0; i < row; ++i) {
    //     j = 0;
    //     for (; j < col; ++j) {
    //         std::cout << land_nums[i][j] << " " << std::endl;
    //     }
    //     std::cout << "\n" << std::endl;
    // }

    Solution solution(land_nums, row, col);
    min_diff = solution.MinDiffInArray();
    std::cout << min_diff << std::endl;
    return 0;
}
