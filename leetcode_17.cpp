// 17. Letter Combinations of a Phone Number
// Given a digit string, return all possible letter combinations that the number could represent.
// A mapping of digit to letters (just like on the telephone buttons) is given below.
// Input:Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].


#include "leetcode.hpp"

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty())  return res;
        helper(res, "", digits, 0);
        return res;
    }
    void helper(vector<string> &res, const string& str, const string& digits, int id)
    {
        static vector<string> tab = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        int idx = digits[id] - '0';
        if(id == digits.size() - 1)
        {
            for(char ch : tab[idx])
                res.push_back(str + ch);
        }
        else
        {
            for(char ch : tab[idx])
                helper(res, str + ch, digits, id + 1);
        }
    }
};


int main(int argc, char const *argv[])
{
    Solution sln;
    vector<string> ans = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    auto result = sln.letterCombinations("23");
    sort(ans.begin(), ans.end());
    sort(result.begin(), result.end());

    CHECK_TRUE(ans == result);
    TEST_REPORT();
}