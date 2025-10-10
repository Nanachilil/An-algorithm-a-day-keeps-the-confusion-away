// Copyright (c) 2025-10-10 by Nana Zhao

#include <iostream>
#include <vector>

class Solution1 {
   public:
    int& num;
    std::vector<std::vector<int>>& matrix;
    Solution1(int& input, std::vector<std::vector<int>>& input_matrix) : num(input), matrix(input_matrix) {}
    virtual ~Solution1() = default;
    std::vector<std::vector<int>> GetMatrix() {
        int writein_num = 0;
        int top = 0, bottom = num - 1, left = 0, right = num - 1;
        while (writein_num < num * num) {
            for (int i = left; i <= right && writein_num < num * num; ++i) {
                matrix[top][i] = ++writein_num;
            }
            ++top;
            for (int i = top; i <= bottom && writein_num < num * num; ++i) {
                matrix[i][right] = ++writein_num;
            }
            --right;
            // if (top <= bottom) {
            for (int i = right; i >= left && writein_num < num * num; --i) {
                matrix[bottom][i] = ++writein_num;
            }
            --bottom;
            // }

            // if (left <= right) {
            for (int i = bottom; i >= top && writein_num < num * num; --i) {
                matrix[i][left] = ++writein_num;
            }
            ++left;
            // }
        }
        return matrix;
    }
};

int main() {
    int n = getchar() - '0';
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, -1));
    Solution1 solution(n, matrix);
    solution.GetMatrix();
    std::cout << "[";
    for (int i = 0, j = 0; i < n; ++i) {
        std::cout << "[";
        for (j = 0; j < n; ++j) {
            std::cout << matrix[i][j];
            if (j != n - 1) {
                std::cout << ",";
            }
        }
        std::cout << "]";
        if (i != n - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
