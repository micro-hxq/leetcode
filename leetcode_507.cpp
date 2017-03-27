// 507. Perfect Number

// We define the Perfect Number is a positive integer that is equal to the sum of 
// all its positive divisors except itself.

// Now, given an integer n, write a function that returns true when it is a perfect 
// number and false when it is not.
// 
// Example:
// Input: 28
// Output: True
// Explanation: 28 = 1 + 2 + 4 + 7 + 14
// 
// Note: The input number n will not exceed 100,000,000. (1e8)

#include "leetcode.hpp"

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 1)    return false;
        int res = 1;
        int i = 2;
        for(; i * i <= num; ++i)
        {
            int j = num / i;
            if(i * j == num)
                res += i + j;
        }
        if(i * i == num)
            res -= i;
        return res == num;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;

    CHECK_TRUE(sln.checkPerfectNumber(28));
    CHECK_FALSE(sln.checkPerfectNumber(5));
    CHECK_FALSE(sln.checkPerfectNumber(2));
    CHECK_FALSE(sln.checkPerfectNumber(1));
    
    TEST_REPORT();
}