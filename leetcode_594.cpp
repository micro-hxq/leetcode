// 594. Longest Harmonious Subsequence

// We define a harmonious array is an array where the difference between its 
// maximum value and its minimum value is exactly 1.

// Now, given an integer array, you need to find the length of its longest 
// harmonious subsequence among all its possible subsequences.

// Example 1:
// Input: [1,3,2,2,5,2,3,7]
// Output: 5
// Explanation: The longest harmonious subsequence is [3,2,2,2,3].

#include "leetcode.hpp"

class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.empty()) return 0;
        map<int, int> aux;
        for(int n : nums)
            ++aux[n];
        int res = 0;
        auto it = aux.begin();
        for(auto prev = it++; it != aux.end(); prev = it++)
        {
            if(it->first - prev->first < 2)
            {
                int cur_num = prev->second + it->second;
                res = res < cur_num ? cur_num : res;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    CHECK_TRUE(sln.findLHS(nums) == 5);

    TEST_REPORT();
}