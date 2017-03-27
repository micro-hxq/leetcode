// 537. Complex Number Multiplication
// Given two strings representing two complex numbers.

// You need to return a string representing their multiplication. Note i2 = -1 according 
// to the definition.

// Example 1:
// Input: "1+1i", "1+1i"
// Output: "0+2i"
// Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the 
// form of 0+2i.

// Example 2:
// Input: "1+-1i", "1+-1i"
// Output: "0+-2i"
// Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the 
// form of 0+-2i.

// Note:

// The input strings will not have extra blank.
// The input strings will be given in the form of a+bi, where the integer a and b 
// will both belong to the range of [-100, 100]. And the output should be also in this form.

#include "leetcode.hpp"

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        auto n1 = helper(a);
        auto n2 = helper(b);
        return to_string(n1.first * n2.first - n1.second * n2.second) + '+' + 
               to_string(n1.first * n2.second + n1.second * n2.first) + 'i';
    }
    pair<int, int> helper(const string& s)
    {
        int num[2] = {0, 0}, flag[2] = {1, 1};
        int i = 0;
        for(size_t j = 0; j < s.size() - 1; ++j)
        {
            char ch = s[j];
            if(ch == '+')
                ++i;
            else if(ch == '-')
                flag[i] = -1;
            else
                num[i] = 10 * num[i] + ch - '0';
        }
        return make_pair(flag[0] * num[0], flag[1] * num[1]);
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    CHECK_TRUE(sln.complexNumberMultiply("0+0i", "0+0i") == "0+0i");
    CHECK_TRUE(sln.complexNumberMultiply("1+1i", "1+1i") == "0+2i");
    CHECK_TRUE(sln.complexNumberMultiply("1+-1i", "1+-1i") == "0+-2i");
    CHECK_TRUE(sln.complexNumberMultiply("2+3i", "3+4i") == "-6+17i");
    TEST_REPORT();
}