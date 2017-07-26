// 628. Maximum Product of Three Numbers

// Given an integer array, find three numbers whose product is maximum and output the maximum product.

// Example 1:
// Input: [1,2,3]
// Output: 6
// Example 2:
// Input: [1,2,3,4]
// Output: 24
// Note:
// The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
// Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.

#include "leetcode.hpp"


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        vector<int> minHeap, maxHeap;
        int len = nums.size();
        for(int i = 0; i < 2; ++i)
        {
            minHeap.push_back(nums[i]);
            maxHeap.push_back(nums[i]);
        }
        make_heap(maxHeap.begin(), maxHeap.end(), less<int>());
        maxHeap.push_back(nums[2]);
        push_heap(maxHeap.begin(), maxHeap.end(), less<int>());
        pop_heap(maxHeap.begin(), maxHeap.end(), less<int>());
        maxHeap.pop_back();
        minHeap.push_back(nums[2]);
        make_heap(minHeap.begin(), minHeap.end(), greater<int>());
        for(int i = 3; i < len; ++i)
        {
            if(nums[i] > minHeap.front())
            {
                minHeap.push_back(nums[i]);
                push_heap(minHeap.begin(), minHeap.end(), greater<int>());
                pop_heap(minHeap.begin(), minHeap.end(), greater<int>());
                minHeap.pop_back();
            }
            else if(nums[i] < maxHeap.front())
            {
                maxHeap.push_back(nums[i]);
                push_heap(maxHeap.begin(), maxHeap.end(), less<int>());
                pop_heap(maxHeap.begin(), maxHeap.end(), less<int>());
                maxHeap.pop_back();
            }
        }
        return max(minHeap[1], minHeap[2]) * max(maxHeap[0] * maxHeap[1], minHeap[0] * min(minHeap[1], minHeap[2]));
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;

    vector<int> nums1 = {1, 2, 3};
    CHECK_TRUE(sln.maximumProduct(nums1) == 6);

    vector<int> nums2 = {1, 2, 3, 4};
    CHECK_TRUE(sln.maximumProduct(nums2) == 24);

    vector<int> nums3 = {1, 2, 3, 4, -5, -6};
    CHECK_TRUE(sln.maximumProduct(nums3) == 120);

    TEST_REPORT();
}