// 540. Single Element in a Sorted Array

// Given a sorted array consisting of only integers where every element appears twice 
// except for one element which appears once. Find this single element that appears only once.

// Example 1:
// Input: [1,1,2,3,3,4,4,8,8]
// Output: 2
// Example 2:
// Input: [3,3,7,7,10,11,11]
// Output: 10
// Note: Your solution should run in O(log n) time and O(1) space.

#include "leetcode.hpp"

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int head = 0, tail = nums.size() - 1;
        while(head < tail)
        {
            int mid = (head + tail) / 2;
            int number = nums[mid];
            if((mid & 1) == 0)
            {
                if(number == nums[mid - 1])
                    tail = mid - 2;
                else if(number == nums[mid + 1])
                    head = mid + 2;
                else
                    return number;

            }
            else
            {
                if(number == nums[mid - 1])
                    head = mid + 1;
                else if(number == nums[mid + 1])
                    tail = mid - 1;
            }
        }
        return nums[head];
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;

    vector<int> nums1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    CHECK_TRUE(sln.singleNonDuplicate(nums1) == 2);
    vector<int> nums2 = {3, 3, 7, 7, 10, 11, 11};
    CHECK_TRUE(sln.singleNonDuplicate(nums2) == 10);
    
    TEST_REPORT();
}