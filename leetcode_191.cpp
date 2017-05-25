// 191. Number of 1 Bits

// Write a function that takes an unsigned integer and returns the number of ’1' 
// bits it has (also known as the Hamming weight).

// For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011,
//  so the function should return 3.

#include "leetcode.hpp"

class Solution {
public:
    int hammingWeight(uint32_t n) {
        // return bitset<32>(n).count();
        int res = 0;
        while(n)
        {
            res += n & 1;
            n >>= 1;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    CHECK_TRUE(sln.hammingWeight(0) == 0);
    CHECK_TRUE(sln.hammingWeight(1) == 1);
    CHECK_TRUE(sln.hammingWeight(2) == 1);
    CHECK_TRUE(sln.hammingWeight(11) == 3);
    TEST_REPORT();
}