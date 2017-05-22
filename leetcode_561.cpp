// 561. Array Partition I
// Given an array of 2n integers, your task is to group these integers into n 
// pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of 
// min(ai, bi) for all i from 1 to n as large as possible.

// Example 1:
// Input: [1,4,3,2]

// Output: 4
// Explanation: n is 2, and the maximum sum of pairs is 4.
// Note:
// n is a positive integer, which is in the range of [1, 10000].
// All the integers in the array will be in the range of [-10000, 10000].

#include "leetcode.hpp"

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for(auto iter = nums.begin(); iter != nums.end(); ++iter, ++iter)
            res += *iter;
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> nums1 = {1, 4, 3, 2};
    CHECK_TRUE(sln.arrayPairSum(nums1) == 4);
    TEST_REPORT();
}