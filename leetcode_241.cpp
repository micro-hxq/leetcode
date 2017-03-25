// 241. Different Ways to Add Parentheses

// Given a string of numbers and operators, return all possible results from 
// computing all the different possible ways to group numbers and operators. 
// The valid operators are +, - and *.

// Example 1
// Input: "2-1-1".

// ((2-1)-1) = 0
// (2-(1-1)) = 2
// Output: [0, 2]

// Example 2
// Input: "2*3-4*5"

// (2*(3-(4*5))) = -34
// ((2*3)-(4*5)) = -14
// ((2*(3-4))*5) = -10
// (2*((3-4)*5)) = -10
// (((2*3)-4)*5) = 10
// Output: [-34, -14, -10, -10, 10]

#include "leetcode.hpp"

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        size_t len = input.size();
        for(size_t i = 0; i < len; ++i)
        {
            char ch = input[i];
            if(ch == '+' || ch == '-' || ch == '*')
            {
                auto res1 = diffWaysToCompute(input.substr(0, i));
                auto res2 = diffWaysToCompute(input.substr(i + 1));
                for(int n1 : res1)
                {
                    for(int n2 : res2)
                    {
                        if(ch == '+')
                            res.push_back(n1 + n2);
                        else if(ch == '-')
                            res.push_back(n1 - n2);
                        else
                            res.push_back(n1 * n2);
                    }
                }
            }
        }
        if(res.empty())
            res.push_back(stoi(input)); 
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> ans1 = {0, 2};
    auto res1 = sln.diffWaysToCompute("2-1-1");
    sort(ans1.begin(), ans1.end());
    sort(res1.begin(), res1.end());
    CHECK_TRUE(ans1.size() == res1.size());
    CHECK_TRUE(ans1 == res1);

    vector<int> ans2 = {-34, -14, -10, -10, 10};
    auto res2 = sln.diffWaysToCompute("2*3-4*5");
    sort(ans2.begin(), ans2.end());
    sort(res2.begin(), res2.end());
    CHECK_TRUE(ans2.size() == res2.size());
    CHECK_TRUE(ans2 == res2);
    TEST_REPORT();
}