// 240. Search a 2D Matrix II

// Write an efficient algorithm that searches for a value in an m x n matrix. 
// This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.
// For example,

// Consider the following matrix:

// [
//   [1,   4,  7, 11, 15],
//   [2,   5,  8, 12, 19],
//   [3,   6,  9, 16, 22],
//   [10, 13, 14, 17, 24],
//   [18, 21, 23, 26, 30]
// ]
// Given target = 5, return true.

// Given target = 20, return false.


#include "leetcode.hpp"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix.front().empty()) return false;
        int rows = matrix.size();
        int cols = matrix.front().size();
        for(int r = 0, c = cols - 1; r < rows && c >= 0;)
        {
            if(matrix[r][c] < target)
                ++r;
            else if(matrix[r][c] > target)
                --c;
            else
                return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    CHECK_TRUE(sln.searchMatrix(matrix, 5));
    CHECK_FALSE(sln.searchMatrix(matrix, 20));

    TEST_REPORT();
}