// 38. Count and Say
// The count-and-say sequence is the sequence of integers beginning as follows:
// 1, 11, 21, 1211, 111221, ...

// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth sequence.

// Note: The sequence of integers will be represented as a string.

#include "leetcode.hpp"

class Solution {
public:
    string countAndSay(int n) {
        string res("1");
        while(n-- > 1)
            res = sequence(res);
        return res;
    }
    string sequence(const string& s)
    {
        string res;
        for(auto iter = s.begin(); iter != s.end();)
        {
            char ch = *iter;
            char cnt = '1';
            while(++iter != s.end() && *iter == ch)
                ++cnt;
            res.push_back(cnt);
            res.push_back(ch);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    CHECK_TRUE(sln.countAndSay(1) == "1");
    CHECK_TRUE(sln.countAndSay(2) == "11");
    CHECK_TRUE(sln.countAndSay(3) == "21");
    CHECK_TRUE(sln.countAndSay(4) == "1211");
    CHECK_TRUE(sln.countAndSay(5) == "111221");
    CHECK_TRUE(sln.countAndSay(10) == "13211311123113112211");
    TEST_REPORT();
}