// 48. Rotate Image

// You are given an n x n 2D matrix representing an image.

// Rotate the image by 90 degrees (clockwise).

// Follow up:
// Could you do this in-place?

#include "leetcode.hpp"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        size_t N = matrix.size();
        for(size_t i = 0; i < N / 2; ++i)
        {
            size_t cols = N - 2 * i - 1;
            for(size_t j = 0; j < cols; ++j)
            {
                int aux = matrix[i][i + j];
                matrix[i][i + j] = matrix[N - i - j- 1][i];
                matrix[N - i - j- 1][i] = matrix[N - i - 1][N - i - j - 1];
                matrix[N - i - 1][N - i - j -1] = matrix[i + j][N - i - 1];
                matrix[i + j][N - i - 1] = aux;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<vector<int>> ans1 = {{1}};
    auto mat1 = ans1;
    sln.rotate(mat1);
    CHECK_TRUE(mat1 == ans1);

    vector<vector<int>> mat2 = {{1, 2}, {4, 3}};
    vector<vector<int>> ans2 = {{4, 1}, {3, 2}};
    sln.rotate(mat2);
    CHECK_TRUE(mat2 == ans2);

    vector<vector<int>> mat3 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<vector<int>> ans3 = {
        {7, 4, 1},
        {8, 5, 2},
        {9, 6, 3}
    };
    sln.rotate(mat3);
    CHECK_TRUE(mat3 == ans3);

    TEST_REPORT();
}