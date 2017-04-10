// 557. Reverse Words in a String III

// Given a string, you need to reverse the order of characters in each word 
// within a sentence while still preserving whitespace and initial word order.

// Example 1:
// Input: "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"
// 
// Note: In the string, each word is separated by single space and there will 
// not be any extra space in the string.

#include "leetcode.hpp"


class Solution {
public:
    string reverseWords(string s) {
        string res, temp;
        res.reserve(s.size() + 1);
        istringstream strm(s);
        while(strm >> temp)
        {
            reverse(temp.begin(), temp.end());
            res += temp + ' ';
        }
        if(!res.empty())
            res.pop_back();
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    CHECK_TRUE(sln.reverseWords("hello") == "olleh");
    CHECK_TRUE(sln.reverseWords("hello world") == "olleh dlrow");
    CHECK_TRUE(sln.reverseWords("Let's take LeetCode contest") == "s'teL ekat edoCteeL tsetnoc");
    TEST_REPORT();
}