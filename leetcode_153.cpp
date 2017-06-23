// 153. Find Minimum in Rotated Sorted Array

// Suppose an array sorted in ascending order is rotated 
// at some pivot unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// Find the minimum element.

// You may assume no duplicate exists in the array.

#include "leetcode.hpp"

class Solution {
public:
    int findMin(vector<int>& nums) {
        int minval = nums.front();
        int lo = 0, hi = nums.size() - 1;
        while(lo + 1 < hi)
        {
            int mid = (lo + hi) / 2;
            lo = nums[mid] > nums[lo] ? mid : lo;
            hi = nums[mid] < nums[hi] ? mid : hi;
        }
        return min(minval, min(nums[lo], nums[hi]));
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    CHECK_TRUE(sln.findMin(nums1) == 0);
    vector<int> nums2 = {1, 2, 3};
    CHECK_TRUE(sln.findMin(nums2) == 1);

    TEST_REPORT();
}