// 70. Climbing Stairs

// You are climbing a stair case. It takes n steps to reach to the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Note: Given n will be a positive integer.

#include "leetcode.hpp"

class Solution {
public:
    // fibonacci sequence
    int climbStairs(int n) {
        vector<int> fib(n + 1, 1);
        for(size_t i = 2; i <= n; ++i)
            fib[i] = fib[i - 1] + fib[i - 2];
        return fib.back();
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    CHECK_TRUE(sln.climbStairs(1) == 1);
    CHECK_TRUE(sln.climbStairs(2) == 2);
    CHECK_TRUE(sln.climbStairs(3) == 3);

    TEST_REPORT();
}