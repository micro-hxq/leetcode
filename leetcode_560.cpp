// 560. Subarray Sum Equals K

// Given an array of integers and an integer k, you need to find the total number 
// of continuous subarrays whose sum equals to k.

// Example 1:
// Input:nums = [1,1,1], k = 2
// Output: 2
// Note:
// The length of the array is in range [1, 20,000].
// The range of numbers in the array is [-1000, 1000] and the range of the integer 
// k is [-1e7, 1e7].
// 

#include "leetcode.hpp"

class Solution {
public:
    // int subarraySum(vector<int>& nums, int k) {
    //     int len = nums.size();
    //     vector<int> aux;
    //     aux.reserve(len);
    //     int ans = 0;
    //     for(int v : nums)
    //         ans += helper(aux, v, k);
    //     return ans;

    // }
    // int helper(vector<int> &aux, int val, int k)
    // {
    //     int cur_ans = 0;
    //     aux.push_back(0);
    //     for(int& v : aux)
    //     {
    //         v += val;
    //         cur_ans += v == k;
    //     }
    //     return cur_ans;
    // }
    
    int subarraySum(vector<int>& nums, int k)
    {
        int sum = 0;
        map<int, int> aux;
        aux[0] = 1;
        int ans = 0;
        for(int v : nums)
        {
            sum += v;
            ans += aux[sum - k];
            aux[sum]++;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> nums1 = {1, 1, 1};
    CHECK_TRUE(sln.subarraySum(nums1, 2) == 2);
    CHECK_TRUE(sln.subarraySum(nums1, 3) == 1);
    
    TEST_REPORT();
}