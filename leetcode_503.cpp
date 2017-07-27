// 503. Next Greater Element II

// Given a circular array (the next element of the last element is the first element of the array), 
// print the Next Greater Number for every element. The Next Greater Number of a number x is the 
// first greater number to its traversing-order next in the array, which means you could search 
// circularly to find its next greater number. If it doesn't exist, output -1 for this number.

// Example 1:
// Input: [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2; 
// The number 2 can't find next greater number; 
// The second 1's next greater number needs to search circularly, which is also 2.
// Note: The length of given array won't exceed 10000.


#include "leetcode.hpp"

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        stack<int> idxStack;
        int len = nums.size();
        for(int i = 0; i < 2 * len; ++i)
        {
            int number = nums[i % len];
            while(!idxStack.empty() && nums[idxStack.top()] < number)
            {
                ans[idxStack.top()] = number;
                idxStack.pop();
            }
            if(i < len)
                idxStack.push(i);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    
    vector<int> nums1 = {1, 2, 1};
    vector<int> ans1 = {2, -1, 2};
    CHECK_TRUE(sln.nextGreaterElements(nums1) == ans1);

    vector<int> nums2 = {2, 2, 2};
    vector<int> ans2 = {-1, -1, -1};
    CHECK_TRUE(sln.nextGreaterElements(nums2) == ans2);

    vector<int> nums3 = {6, 5, 4, 3, 2, 1};
    vector<int> ans3 = {-1, 6, 6, 6, 6, 6};
    CHECK_TRUE(sln.nextGreaterElements(nums3) == ans3);

    vector<int> nums4 = {};
    vector<int> ans4 = {};
    CHECK_TRUE(sln.nextGreaterElements(nums4) == ans4);

    vector<int> nums5 = {1, 2, 3, 4, 5};
    vector<int> ans5 = {2, 3, 4, 5, -1};
    CHECK_TRUE(sln.nextGreaterElements(nums5) == ans5);

    TEST_REPORT();
}