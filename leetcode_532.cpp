// 532. K-diff Pairs in an Array

// Given an array of integers and an integer k, you need to find the number of 
// unique k-diff pairs in the array. Here a k-diff pair is defined as an integer 
// pair (i, j), where i and j are both numbers in the array and their absolute 
// difference is k.

// Example 1:
// Input: [3, 1, 4, 1, 5], k = 2
// Output: 2
// Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
// Although we have two 1s in the input, we should only return the number of unique pairs.
// Example 2:
// Input:[1, 2, 3, 4, 5], k = 1
// Output: 4
// Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
// Example 3:
// Input: [1, 3, 1, 5, 4], k = 0
// Output: 1
// Explanation: There is one 0-diff pair in the array, (1, 1).

// Note:
// The pairs (i, j) and (j, i) count as the same pair.
// The length of the array won't exceed 10,000.
// All the integers in the given input belong to the range: [-1e7, 1e7].

#include "leetcode.hpp"

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0)   return 0;
        sort(nums.begin(), nums.end());
        auto iter1 = nums.begin();
        int res = 0;
        for(auto iter2 = iter1; iter1 != nums.end() && iter2 != nums.end();)
        {
            if(iter1 == iter2)
                ++iter2;
            else
            {
                int v1 = *iter1;
                int v2 = *iter2;
                if(v1 + k == v2)
                {
                    ++res;
                    while(++iter1 != nums.end() && *iter1 == v1);
                    while(++iter2 != nums.end() && *iter2 == v2);
                }
                else if(v1 + k < v2)
                    while(++iter1 != nums.end() && *iter1 == v1);
                else
                    while(++iter2 != nums.end() && *iter2 == v2);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> nums1 = {3, 1, 4, 1, 5};
    CHECK_TRUE(sln.findPairs(nums1, 2) == 2);
    vector<int> nums2 = {1, 2, 3, 4, 5};
    CHECK_TRUE(sln.findPairs(nums2, 1) == 4);
    vector<int> nums3 = {1, 3, 1, 5, 4};
    CHECK_TRUE(sln.findPairs(nums3, 0) == 1);
    CHECK_TRUE(sln.findPairs(nums3, -1) == 0);
    TEST_REPORT();
}