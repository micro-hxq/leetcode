// 74. Search a 2D Matrix

// Write an efficient algorithm that searches for a value in an m x n matrix. 
// This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
// For example,

// Consider the following matrix:

// [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// Given target = 3, return true.

#include "leetcode.hpp"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix.front().empty()) return false;
        int rows = matrix.size();
        int cols = matrix.front().size();
        // int head = 0, tail = rows - 1;
        // while(head < tail)
        // {
        //     int mid = (head + tail) / 2;
        //     if(matrix[mid][0] < target)
        //         head = mid + 1;
        //     else
        //         tail = mid;
        // }
        // if(matrix[head][0] == target) return true;
        // int r=  matrix[head][0] < target ? head : head - 1;
        // head = 0, tail = cols - 1;
        // while(head < tail)
        // {
        //     int mid = (head + tail) / 2;
        //     if(matrix[r][mid] < target)
        //         head = mid + 1;
        //     else
        //         tail = mid;
        // }
        // if(matrix[r][head] == target) return true;
        // return false;

        int head = 0, tail = rows * cols - 1;
        while(head < tail)
        {
            int mid = (head + tail) / 2;
            if(matrix[mid / cols][mid % cols] < target)
                head = mid + 1;
            else 
                tail = mid;
        }
        return (matrix[head / cols][head % cols] == target);
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;

    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };

    CHECK_TRUE(sln.searchMatrix(matrix, 3));
    CHECK_TRUE(sln.searchMatrix(matrix, 50));
    CHECK_FALSE(sln.searchMatrix(matrix, 49));

    TEST_REPORT();
}