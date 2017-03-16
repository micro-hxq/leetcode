// 287. Find the Duplicate Number 

// Given an array nums containing n + 1 integers where each integer is between 
// 1 and n (inclusive), prove that at least one duplicate number must exist. 
// Assume that there is only one duplicate number, find the duplicate one.

// Note:
// You must not modify the array (assume the array is read only).
// You must use only constant, O(1) extra space.
// Your runtime complexity should be less than O(n2).
// There is only one duplicate number in the array, but it could be repeated more 
// than once.

#include "leetcode.hpp"

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[nums[0]];
        int slow = nums[0];
        while(fast != slow)
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        fast = 0;
        while(fast != slow)
        {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> nums1 = {1, 1};
    CHECK_TRUE(sln.findDuplicate(nums1) == 1);
    vector<int> nums2 = {2, 1, 3, 3};
    CHECK_TRUE(sln.findDuplicate(nums2) == 3);
    vector<int> nums3 = {1, 2, 3, 4, 4, 4, 4};
    CHECK_TRUE(sln.findDuplicate(nums3) == 4);
    vector<int> nums4 = {2, 5, 9, 6, 9, 3, 8, 9, 7, 1};
    CHECK_TRUE(sln.findDuplicate(nums4) == 9);
    TEST_REPORT();
}