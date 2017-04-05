// 39. Combination Sum

// Given a set of candidate numbers (C) (without duplicates) and a target 
// number (T), find all unique combinations in C where the candidate numbers 
// sums to T.

// The same repeated number may be chosen from C unlimited number of times.

// Note:
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.

// For example, given candidate set [2, 3, 6, 7] and target 7, 
// A solution set is: 
// [
//   [7],
//   [2, 2, 3]
// ]

#include "leetcode.hpp"

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> aux;
        helper(res, aux, candidates, target);
        return res;
    }

    void helper(vector<vector<int>>& res, vector<int>& aux, vector<int>& candidate, int target)
    {
        if(target < 0)  return;
        if(target == 0) 
        {
            res.push_back(aux);
            return;
        }
        for(int num : candidate)
        {
            if(aux.empty() || num >= aux.back())
            {
                aux.push_back(num);
                helper(res, aux, candidate, target - num);
                aux.pop_back();
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> candidate = {2, 3, 6, 7};
    vector<vector<int>> ans1 = {{7}, {2, 2, 3}};
    auto res1 = sln.combinationSum(candidate, 7);
    sort(ans1.begin(), ans1.end());
    sort(res1.begin(), res1.end());

    CHECK_TRUE(ans1.size() == res1.size());
    CHECK_TRUE(ans1 == res1);

    TEST_REPORT();
}