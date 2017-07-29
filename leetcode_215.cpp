// 215. Kth Largest Element in an Array

// Find the kth largest element in an unsorted array. Note that it is the kth 
// largest element in the sorted order, not the kth distinct element.

// For example,
// Given [3,2,1,5,6,4] and k = 2, return 5.

// Note: 
// You may assume k is always valid, 1 ? k ? array's length.

#include "leetcode.hpp"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        return helper(nums, 0, len - 1, k);
    }

    int helper(vector<int> &nums, int begin, int end, int k)
    {
        int pivot = partition(nums, begin, end);
        if(pivot < k - 1) return helper(nums, pivot + 1,  end, k);
        if(pivot > k - 1) return helper(nums, begin, pivot - 1, k);
        return nums[pivot];
    }
    int partition(vector<int> &nums, int begin, int end)
    {
        int val = nums[end];
        int first = begin;
        for(; begin < end; ++begin)
        {
            if(nums[begin] > val)
            {
                swap(nums[first], nums[begin]);
                ++first;
            }
        }
        swap(nums[first], nums[end]);
        return first;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    CHECK_TRUE(sln.findKthLargest(nums, 2) == 5);

    TEST_REPORT();
}