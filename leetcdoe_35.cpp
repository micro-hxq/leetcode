// 35. Search Insert Position

// Given a sorted array and a target value, return the index if the target is 
// found. If not, return the index where it would be if it were inserted in order.

// You may assume no duplicates in the array.

// Here are few examples.
// [1,3,5,6], 5 → 2
// [1,3,5,6], 2 → 1
// [1,3,5,6], 7 → 4
// [1,3,5,6], 0 → 0

#include "leetcode.hpp"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        size_t len = nums.size();
        int i = 0, j = len - 1, mid;
        while(i < j)
        {
            mid = (i + j) / 2;
            if(nums[mid] < target)
                i = mid  + 1;
            else if(nums[mid] > target)
                j = mid - 1;
            else
            {
                i = mid;
                break;
            }
        }
        return nums[i] < target ? i + 1 : i;
    }
};


int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> nums = {1, 3, 5, 6};
    
    CHECK_TRUE(sln.searchInsert(nums, 5) == 2);
    CHECK_TRUE(sln.searchInsert(nums, 2) == 1);
    CHECK_TRUE(sln.searchInsert(nums, 7) == 4);
    CHECK_TRUE(sln.searchInsert(nums, 0) == 0);

    TEST_REPORT();
}