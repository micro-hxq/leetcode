// 367. Valid Perfect Square
// Given a positive integer num, write a function which returns True if num 
// is a perfect square else False.
// Note: Do not use any built-in library function such as sqrt.

// Example 1:

// Input: 16
// Returns: True
// Example 2:

// Input: 14
// Returns: False

#include "leetcode.hpp"

class Solution {
public:
    bool isPerfectSquare(int num) {
        int mod = num % 10;
        if(mod == 2 || mod == 3 || mod == 7 || mod == 8)
            return false;
        for(int i = 1; i * i <= num; ++i)
            if(i * i == num)
                return true;
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;

    CHECK_TRUE(sln.isPerfectSquare(1));
    CHECK_TRUE(sln.isPerfectSquare(4));
    CHECK_TRUE(sln.isPerfectSquare(9));
    CHECK_TRUE(sln.isPerfectSquare(16));
    CHECK_TRUE(sln.isPerfectSquare(25));
    CHECK_TRUE(sln.isPerfectSquare(36));
    CHECK_TRUE(sln.isPerfectSquare(49));
    CHECK_TRUE(sln.isPerfectSquare(64));
    CHECK_TRUE(sln.isPerfectSquare(81));
    CHECK_TRUE(sln.isPerfectSquare(100));
    
    CHECK_FALSE(sln.isPerfectSquare(2));
    CHECK_FALSE(sln.isPerfectSquare(222));
    CHECK_FALSE(sln.isPerfectSquare(222222));
    CHECK_FALSE(sln.isPerfectSquare(2393));
    CHECK_FALSE(sln.isPerfectSquare(98947));
    CHECK_FALSE(sln.isPerfectSquare(9648));

    TEST_REPORT();
}