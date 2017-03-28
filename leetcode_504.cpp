// 504. Base 7
// Given an integer, return its base 7 string representation.

// Example 1:
// Input: 100
// Output: "202"

// Example 2:
// Input: -7
// Output: "-10"
// Note: The input will be in range of [-1e7, 1e7].

#include "leetcode.hpp"

class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)    return "0";
        string res;
        bool nega = false;
        if(num < 0)
        {
            num = -num;
            nega = true;
        }
        while(num)
        {
            int mod = num % 7;
            num /= 7;
            res.push_back(mod + '0');
        }
        if(nega)
            res.push_back('-');
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    CHECK_TRUE(sln.convertToBase7(100) == "202");
    CHECK_TRUE(sln.convertToBase7(-7) ==  "-10");
    CHECK_TRUE(sln.convertToBase7(7) == "10");
    CHECK_TRUE(sln.convertToBase7(0) == "0");
    TEST_REPORT();
}