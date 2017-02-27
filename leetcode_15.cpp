// 15. 3Sum
// Given an array S of n integers, are there elements a, b, c in S such that 
// a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

// For example, given array S = [-1, 0, 1, 2, -1, -4],

// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

#include "leetcode.hpp"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        size_t len = nums.size();
        if(len < 3) return res;
        sort(nums.begin(), nums.end());
        for(size_t i = 0; i < len - 2;)
        {
            int v1 = nums[i];
            int minval = v1 + nums[i + 1] + nums[i + 2];
            int maxval = v1 + nums[len - 1] + nums[len - 2];
            if(minval > -v1)
                break;
            else if(!(maxval < -v1))
            {
                size_t j = i + 1, k = len - 1;
                while(j < k)
                {
                    int v2 = nums[j], v3 = nums[k];
                    int sum2 = v2 + v3;
                    if(sum2 < -v1)
                        ++j;
                    else if(sum2 > -v1)
                        --k;
                    else
                    {
                        res.push_back({v1, v2, v3});
                        while(++j < k && v2 == nums[j]);
                        while(--k > j && v3 == nums[k]);
                    }
                }
            }
            while(++i < len - 2 && v1 == nums[i]);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = { {-1, 0, 1}, {-1, -1, 2}};
    auto res = sln.threeSum(nums);
    sort(ans.begin(), ans.end());
    sort(res.begin(), res.end());

    CHECK_TRUE(ans.size() == res.size());
    CHECK_TRUE(ans == res);
    TEST_REPORT();
}