// 264. Ugly Number II

// Write a program to find the n-th ugly number.

// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 
// 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

// Note that 1 is typically treated as an ugly number, and n does not exceed 1690.

#include "leetcode.hpp"

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0) return 0;
        vector<int> aux(1690, 0);
        aux[0] = 1;
        int next = 1, idx2 = 0, idx3 = 0, idx5 = 0;
        while(next < n)
        {
            int minval = min(min(2 * aux[idx2], 3 * aux[idx3]), 5 * aux[idx5]);
            aux[next++] = minval;
            while(2 * aux[idx2] <= minval) ++idx2;
            while(3 * aux[idx3] <= minval) ++idx3;
            while(5 * aux[idx5] <= minval) ++idx5;
        }
        return aux[n - 1];
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;

    CHECK_TRUE(sln.nthUglyNumber(1) == 1);
    CHECK_TRUE(sln.nthUglyNumber(2) == 2);
    CHECK_TRUE(sln.nthUglyNumber(3) == 3);
    CHECK_TRUE(sln.nthUglyNumber(10) == 12);

    TEST_REPORT();
}