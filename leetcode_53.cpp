// 53. Maximum Subarray
// Find the contiguous subarray within an array (containing at least one number) 
// which has the largest sum.

// For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
// the contiguous subarray [4,-1,2,1] has the largest sum = 6.
// More practice:
// If you have figured out the O(n) solution, try coding another solution using 
// the divide and conquer approach, which is more subtle.

#include "leetcode.hpp"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int summax = INT_MIN, sum = 0;
        for(int elem : nums)
        {
            sum += elem;
            summax = max(sum, summax);
            sum = max(sum, 0);
        }
        return summax;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    CHECK_TRUE(sln.maxSubArray(nums) == 6);
    nums = {-2, -1, -5, -4, -3};
    CHECK_TRUE(sln.maxSubArray(nums) == -1);
    TEST_REPORT();
}