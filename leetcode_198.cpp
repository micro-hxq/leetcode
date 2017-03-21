// 198. House Robber

// You are a professional robber planning to rob houses along a street. 
// Each house has a certain amount of money stashed, the only constraint 
// stopping you from robbing each of them is that adjacent houses have security 
// system connected and it will automatically contact the police if two adjacent 
// houses were broken into on the same night.

// Given a list of non-negative integers representing the amount of money of each 
// house, determine the maximum amount of money you can rob tonight without alerting 
// the police.

#include "leetcode.hpp"

class Solution {
public:
    int rob(vector<int>& nums) {
        int p1 = 0, p2 = 0;
        for(int val : nums)
        {
            val = p2 + val > p1 ? p2 + val : p1;
            p2 = p1;
            p1 = val;
        }
        return p1;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> nums1 = {1, 2, 3, 4, 5};
    CHECK_TRUE(sln.rob(nums1) == 9);

    vector<int> nums2 = {10, 2, 3, 10, 2, 9, 12, 2};
    CHECK_TRUE(sln.rob(nums2) == 32);
    TEST_REPORT();
}