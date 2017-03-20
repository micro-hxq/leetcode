// 22. Generate Parentheses

// Given n pairs of parentheses, write a function to generate all combinations 
// of well-formed parentheses.

// For example, given n = 3, a solution set is:

// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

#include "leetcode.hpp"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(n, 0, res, "");
        return res;
    }

    void helper(int left, int right, vector<string>& res, string aux)
    {
        if(left > 0)
            helper(left - 1, right + 1, res, aux + '(');
        if(right > 0)
            helper(left, right - 1, res, aux + ')');
        if(left == 0 && right == 0)
            res.push_back(aux);
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<string> ans = {"((()))", "(()())", "(())()", "()(())", "()()()"};
    auto res = sln.generateParenthesis(3);
    CHECK_TRUE(ans.size() == res.size());
    CHECK_TRUE(ans == res);

    // auto res1 = sln.generateParenthesis(5);
    // int i = 0;
    // for(const auto& e : res1)
    //     cout << ++i << ": " << e << '\n';

    TEST_REPORT();
}