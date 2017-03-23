// 89. Gray Code

// The gray code is a binary numeral system where two successive values differ 
// in only one bit.

// Given a non-negative integer n representing the total number of bits in the 
// code, print the sequence of gray code. A gray code sequence must begin with 0.

// For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2

// Note:
// For a given n, a gray code sequence is not uniquely defined.

// For example, [0,2,3,1] is also a valid gray code sequence according to the above 
// definition.

// For now, the judge is able to judge based on one instance of gray code sequence. 
// Sorry about that.

#include "leetcode.hpp"

class Solution {
public:
    vector<int> grayCode(int n) {
        int num = pow(2, n);
        vector<int> res(num, 0);
        if(n == 0)  return res;
        int base = 1, high = 1, mirror = 0;
        for(int i = 1; i < num; ++i)
        {
            if(i == high)
            {
                base = high;
                high *= 2;
                mirror = i;
            }
            res[i] = res[--mirror] + base;
        }
        return res;
    }
};

class GrayCodeValidator {
public:
    static bool validate(const vector<int>& v)
    {
        int num = v.size();
        while(num > 1)
        {
            int i = 0, j = num - 1;
            num /= 2;
            for(; i < j; ++i, --j)
            {
                if(v[i] + num != v[j])
                    return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;

    CHECK_TRUE(GrayCodeValidator::validate(sln.grayCode(0)));
    CHECK_TRUE(GrayCodeValidator::validate(sln.grayCode(1)));
    CHECK_TRUE(GrayCodeValidator::validate(sln.grayCode(2)));
    CHECK_TRUE(GrayCodeValidator::validate(sln.grayCode(3)));
    CHECK_TRUE(GrayCodeValidator::validate(sln.grayCode(4)));
    CHECK_TRUE(GrayCodeValidator::validate(sln.grayCode(8)));
    CHECK_TRUE(GrayCodeValidator::validate(sln.grayCode(16)));

    TEST_REPORT();
}