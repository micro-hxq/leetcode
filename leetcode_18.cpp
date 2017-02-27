// 18. 4Sum
// Given an array S of n integers, are there elements a, b, c,
// and d in S such that a + b + c + d = target? Find all unique
// quadruplets in the array which gives the sum of target.

// For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]

#include "leetcode.hpp"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        size_t len = nums.size();
        if(len < 4) return res;
        sort(nums.begin(), nums.end());
        for(size_t i1 = 0; i1 < len - 3;)
        {
            int v1 = nums[i1];
            for(size_t i2 = i1 + 1; i2 < len - 2;)
            {
                int v2 = nums[i2];
                int minval = v1 + v2 + nums[i2 + 1] + nums[i2 + 2];
                int maxval = v1 + v2 + nums[len - 1] + nums[len - 2];
                if(minval > target)
                    break;
                else if(!(maxval < target))
                {
                    size_t i = i2 + 1, j = len - 1;
                    int sum2 = target - v1 - v2;
                    while(i < j)
                    {
                        int val = nums[i] + nums[j];
                        if(val < sum2)
                            ++i;
                        else if(val > sum2)
                            --j;
                        else
                        {
                            int v3 = nums[i], v4 = nums[j];
                            res.push_back({v1, v2, v3, v4});
                            while(++i < j && v3 == nums[i]);
                            while(--j > i && v4 == nums[j]);
                        }
                    }
                }
                while(++i2 < len - 2 && v2 == nums[i2]);
            }
            while(++i1 < len - 1 && v1 == nums[i1]);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> ans = {
                          {-1,  0, 0, 1},
                          {-2, -1, 1, 2},
                          {-2,  0, 0, 2}
                        };
    sort(ans.begin(), ans.end());
    auto res = sln.fourSum(nums, 0);
    sort(res.begin(), res.end());

    CHECK_TRUE(ans.size() == res.size());
    CHECK_TRUE(ans == res);
    TEST_REPORT();
}