// 390. Elimination Game

// There is a list of sorted integers from 1 to n. Starting from left to 
// right, remove the first number and every other number afterward until 
// you reach the end of the list.

// Repeat the previous step again, but this time from right to left, remove 
// the right most number and every other number from the remaining numbers.

// We keep repeating the steps again, alternating left to right and right to 
// left, until a single number remains.

// Find the last number that remains starting with a list of length n.

// Example:

// Input:
// n = 9,
// 1 2 3 4 5 6 7 8 9
// 2 4 6 8
// 2 6
// 6

// Output:
// 6

#include "leetcode.hpp"

class Solution {
public:
    int lastRemaining(int n) {
        return n == 1 ? 1 : 2 * (n / 2 - lastRemaining(n / 2) + 1);
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    CHECK_TRUE(sln.lastRemaining(1) == 1);
    CHECK_TRUE(sln.lastRemaining(2) == 2);
    CHECK_TRUE(sln.lastRemaining(3) == 2);
    CHECK_TRUE(sln.lastRemaining(4) == 2);
    CHECK_TRUE(sln.lastRemaining(5) == 2);
    CHECK_TRUE(sln.lastRemaining(6) == 4);
    CHECK_TRUE(sln.lastRemaining(9) == 6);
    TEST_REPORT();
}