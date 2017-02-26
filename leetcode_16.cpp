//  16. 3Sum Closest
//  Given an array S of n integers, find three integers in S such that the sum
//  is closest to a given number, target. Return the sum of the three integers.
//  You may assume that each input would have exactly one solution.
//  
//  For example, given array S = {-1 2 1 -4}, and target = 1.
//  The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

#include "leetcode.hpp"

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = 0, mindiff = INT_MAX;
        size_t len = nums.size();
        sort(nums.begin(), nums.end());
        for(size_t i = 0; i < len; ++i)
        {
            for(size_t j = i + 1, k = len - 1; j < k;)
            {
                int sum = nums[i] + nums[j] + nums[k];
                int diff = sum - target;
                if(diff == 0)
                    return target;
                if(abs(diff) < mindiff)
                {
                    mindiff = abs(diff);
                    closest = sum;
                }
                j += diff < 0 ? 1 : 0;
                k -= diff > 0 ? 1 : 0;
            }
        }
        return closest;
    }
};


int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> nums = {-1, 2, 1, -4};
    CHECK_TRUE(sln.threeSumClosest(nums, 1) == 2);
    TEST_REPORT();
}
