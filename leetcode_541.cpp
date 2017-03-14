// 541. Reverse String II

// Given a string and an integer k, you need to reverse the first k characters 
// for every 2k characters counting from the start of the string. If there are 
// less than k characters left, reverse all of them. If there are less than 
// 2k but greater than or equal to k characters, then reverse the first k 
// characters and left the other as original.

// Example:
// Input: s = "abcdefg", k = 2
// Output: "bacdfeg"

// Restrictions:
// The string consists of lower English letters only.
// Length of the given string and k will in the range [1, 10000]


#include "leetcode.hpp"

class Solution {
public:
    string reverseStr(string s, int k) {
        int N = k / 2;
        int cur = 0, len = s.size();
        while(cur < len)
        {
            if(cur + k < len)
            {
                for(int i = 0; i < N; ++i)
                    swap(s[cur + i], s[cur + k - 1 - i]);                
            }
            else
            {
                int last = len - 1;
                int first = cur;
                while(first < last)
                    swap(s[first++], s[last--]);
            }
            cur += 2 * k;
        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    CHECK_TRUE(sln.reverseStr("abcdefg", 2) == "bacdfeg");
    CHECK_TRUE(sln.reverseStr("abs", 10) == "sba");
    TEST_REPORT();
}