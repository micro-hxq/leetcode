// 62. Unique Paths

// A robot is located at the top-left corner of a m x n grid 
// (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point 
// in time. The robot is trying to reach the bottom-right corner 
// of the grid (marked 'Finish' in the diagram below).

// How many possible unique paths are there?

#include "leetcode.hpp"

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1)    return 1;
        vector<int> rvec(n, 1);
        for(int r = 1; r < m; ++r)
            for(int c = 1; c < n; ++c)
                rvec[c] += rvec[c - 1];
        return rvec.back();
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    
    CHECK_TRUE(sln.uniquePaths(1, 100) == 1);
    CHECK_TRUE(sln.uniquePaths(100, 1) == 1);
    CHECK_TRUE(sln.uniquePaths(2, 2) == 2);
    CHECK_TRUE(sln.uniquePaths(2, 4) == 4);
    CHECK_TRUE(sln.uniquePaths(3, 4) == 10);

    TEST_REPORT();
}