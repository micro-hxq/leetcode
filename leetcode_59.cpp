// 59. Spiral Matrix II

// Given an integer n, generate a square matrix filled with elements 
// from 1 to n^2 in spiral order.

// For example,
// Given n = 3,

// You should return the following matrix:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]

#include "leetcode.hpp"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int curnum = 0, end = n * n;
        vector<vector<int>> res(n, vector<int>(n, 0));
        int row = 0, col = -1;
        int need = n;

        while(true)
        {
            for(int i = 0; i < need; ++i)
                res[row][++col] = ++curnum;
            if(curnum == end)
                break;

            --need;
            for(int i = 0; i < need; ++i)
                res[++row][col] = ++curnum;
            if(curnum == end)
                break;

            for(int i = 0; i < need; ++i)
                res[row][--col] = ++curnum;
            if(curnum == end)
                break;

            --need;
            for(int i = 0; i < need; ++i)
                res[--row][col] = ++curnum;
            if(curnum == end)
                break;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;

    vector<vector<int>> ans1 = {{1}};
    vector<vector<int>> ans2 = {{1, 2}, {4, 3}};
    vector<vector<int>> ans3 = 
    {
        {1, 2, 3},
        {8, 9, 4},
        {7, 6, 5}
    };

    CHECK_TRUE(sln.generateMatrix(1) == ans1);
    CHECK_TRUE(sln.generateMatrix(2) == ans2);
    CHECK_TRUE(sln.generateMatrix(3) == ans3);

    TEST_REPORT();
}