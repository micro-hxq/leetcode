// 643. Maximum Average Subarray I

// Given an array consisting of n integers, find the contiguous subarray of given 
// ength k that has the maximum average value. And you need to output the maximum average value.

// Example 1:
// Input: [1,12,-5,-6,50,3], k = 4
// Output: 12.75
// Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
// Note:
// 1 <= k <= n <= 30,000.
// Elements of the given array will be in the range [-10,000, 10,000].

#include "leetcode.hpp"

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long maxval = 0, curval = 0;
        auto head = nums.begin();
        for(int i = 0; i < k; ++i)
            curval += *head++;
        maxval = curval;
        auto tail = nums.begin();
        for(; head != nums.end(); ++head, ++tail)
        {
            curval += (*head - *tail);
            maxval = curval > maxval ? curval : maxval;
        }
        return 1.0 * maxval / k;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    CHECK_TRUE(abs(sln.findMaxAverage(nums, 4) - 12.75) < 1e-8);

    TEST_REPORT();
}