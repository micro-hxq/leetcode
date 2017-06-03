// 581. Shortest Unsorted Continuous Subarray

// Given an integer array, you need to find one continuous subarray that if 
// you only sort this subarray in ascending order, then the whole array will 
// be sorted in ascending order, too.

// You need to find the shortest such subarray and output its length.

// Example 1:
// Input: [2, 6, 4, 8, 10, 9, 15]
// Output: 5
// Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the 
// whole array sorted in ascending order.

// Note:
// Then length of the input array is in range [1, 10,000].
// The input array may contain duplicates, so ascending order here means <=.

#include "leetcode.hpp"

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // if(nums.empty()) return 0;
        // size_t N = nums.size();
        // size_t i = 1;
        // int minid = 0;
        // for(; i < N; ++i)
        // {
        //     if(nums[i] < nums[i - 1])
        //     {
        //         int j = i - 1;
        //         while(j >= 0 && nums[j] > nums[i])
        //             --j;
        //         minid = j + 1;
        //         break;
        //     }
        // }
        // int max = nums[minid], maxid = -1;
        // for(; i < N; ++i)
        // {
        //     if(nums[i] < nums[i - 1])
        //         max = max < nums[i - 1] ? nums[i - 1] : max;
        //     if(nums[i] < max)
        //     {
        //         maxid = i;
        //         int j = minid - 1;
        //         while(j >= 0 && nums[j] > nums[i])
        //             --j;
        //         minid = j + 1;
        //     }
        // }
        // return maxid - minid + 1;
        if(nums.empty()) return 0;
        int N = nums.size(), begin = 0, end = -1, min = nums.back(), max = nums.front();
        for(int i = 1; i < N; ++i)
        {
            min = min < nums[N - 1 - i] ? min : nums[N - 1 - i];
            max = max < nums[i] ? nums[i] : max;
            if(nums[N - 1 - i] > min) 
                begin = N - 1 - i;
            if(nums[i] < max)
                end = i;
        }
        return end - begin + 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> nums1 = {2, 6, 4, 8, 10, 9, 15};
    CHECK_TRUE(sln.findUnsortedSubarray(nums1) == 5);
    vector<int> nums2 = {1, 2, 3, 4};
    CHECK_TRUE(sln.findUnsortedSubarray(nums2) == 0);
    vector<int> nums3 = {2, 3, 3, 2, 4};
    CHECK_TRUE(sln.findUnsortedSubarray(nums3) == 3);
    vector<int> nums4 = {2, 1};
    CHECK_TRUE(sln.findUnsortedSubarray(nums4) == 2);
    vector<int> nums5 = {1, 3, 5, 4, 2};
    CHECK_TRUE(sln.findUnsortedSubarray(nums5) == 4);
    TEST_REPORT();
}