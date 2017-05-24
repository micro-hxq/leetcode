// 202. Happy Number

// Write an algorithm to determine if a number is "happy".

// A happy number is a number defined by the following process: 
// Starting with any positive integer, replace the number by the sum of the squares
// of its digits, and repeat the process until the number equals 1 (where it will 
// stay), or it loops endlessly in a cycle which does not include 1. Those numbers
// for which this process ends in 1 are happy numbers.

// Example: 19 is a happy number

// 1^2 + 9^2 = 82
// 8^2 + 2^2 = 68
// 6^2 + 8^2 = 100
// 1^2 + 0^2 + 0^2 = 1

#include "leetcode.hpp"

class Solution {
public:
    bool isHappy(int n) {
        // unordered_set<int> aux;
        // aux.insert(n);
        // while(true)
        // {
        //     int next = 0;
        //     for(; n != 0; n /= 10)
        //     {
        //         int digit = n % 10;
        //         next += digit * digit;
        //     }
        //     if(next == 1) return true;
        //     if(aux.insert(next).second == false) break;
        //     n = next;
        // }
        // return false;
        int step1 = n, step2 = n;
        do {
            step1 = nextNumber(step1);
            step2 = nextNumber(step2);
            step2 = nextNumber(step2);
        } while(step1 != step2);
        return step1 == 1;
    }
    int nextNumber(int n)
    {
        int next = 0;
        for(; n != 0; n /= 10)
        {
            int digit = n % 10;
            next += digit * digit;
        }
        return next;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    CHECK_TRUE(sln.isHappy(19));
    CHECK_TRUE(sln.isHappy(1));
    CHECK_FALSE(sln.isHappy(2));
    TEST_REPORT();
}