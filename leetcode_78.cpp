// 78. Subsets

// Given a set of distinct integers, nums, return all possible subsets.

// Note: The solution set must not contain duplicate subsets.

// For example,
// If nums = [1,2,3], a solution is:

// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

#include "leetcode.hpp"

class Solution {
    using IterType = typename vector<int>::iterator;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> aux;
        res.push_back(aux);
        helper(res, aux, nums.begin(), nums.end());
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& cur, IterType first, IterType last)
    {
        for(; first != last; ++first)
        {
            cur.push_back(*first);
            res.push_back(cur);
            helper(res, cur, first + 1, last);
            cur.pop_back();
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans3 = 
    {
        {3},
        {1},
        {2},
        {1, 2, 3},
        {1, 3},
        {2, 3},
        {1, 2},
        {}
    };
    auto res3 = sln.subsets(nums);
    CHECK_TRUE(ans3.size() == res3.size());
    size_t N = ans3.size();
    for(size_t i = 0; i < N; ++i)
    {
        sort(ans3[i].begin(), ans3[i].end());
        sort(res3[i].begin(), res3[i].end());
    }
    sort(ans3.begin(), ans3.end());
    sort(res3.begin(), res3.end());
    CHECK_TRUE(ans3 == res3);

    TEST_REPORT();
}