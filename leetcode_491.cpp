// 491. Increasing Subsequences

// Given an integer array, your task is to find all the different possible 
// increasing subsequences of the given array, and the length of an increasing 
// subsequence should be at least 2 .

// Example:
// Input: [4, 6, 7, 7]
// Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
// Note:
// The length of the given array will not exceed 15.
// The range of integer in the given array is [-100,100].
// The given array may contain duplicates, and two equal integers should also 
// be considered as a special case of increasing sequence.

#include "leetcode.hpp"

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3) return res;
        res.push_back(vector<int>());
        set<vector<int>> vs;
        vector<int> aux(15, 0);
        for(int i = 0; i < nums.size(); ++i)
        {
            int len = res.size();
            for(int j = 0; j < len; ++j)
            {
                aux = res[j];
                if(!aux.empty() && aux.back() > nums[i]) continue;
                aux.push_back(nums[i]);
                if(vs.find(aux) == vs.end())
                {
                    vs.insert(aux);
                    res.push_back(aux);
                }
            }

        }
        vector<vector<int>> ans;
        for(vector<int>& v : res)
            if(v.size() > 1) ans.push_back(std::move(v));
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> nums = {4, 6, 7, 7};
    vector<vector<int>> ans = {{4, 6}, {4, 7}, {4, 6, 7}, {4, 6, 7, 7}, 
                                {6, 7}, {6, 7, 7}, {7, 7}, {4, 7, 7}};
    auto res = sln.findSubsequences(nums);
    sort(ans.begin(), ans.end());
    sort(res.begin(), res.end());
    CHECK_TRUE(ans.size() == res.size());
    CHECK_TRUE(ans == res);

    TEST_REPORT();
}