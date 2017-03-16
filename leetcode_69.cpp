// 69. Sqrt(x)

// Implement int sqrt(int x).

// Compute and return the square root of x.

#include "leetcode.hpp"

class Solution {
public:
    int mySqrt(int x) {
        long x1 = x;
        while(x1 * x1 > x)
            x1 = (x1 + x / x1) / 2;
        return x1;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    CHECK_TRUE(sln.mySqrt(4) == 2);
    CHECK_TRUE(sln.mySqrt(9) == 3);
    CHECK_TRUE(sln.mySqrt(16) == 4);
    CHECK_TRUE(sln.mySqrt(225) == 15);
    CHECK_TRUE(sln.mySqrt(625) == 25);
    TEST_REPORT();
}