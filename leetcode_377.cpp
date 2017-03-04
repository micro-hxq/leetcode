// 377. Combination Sum IV
// Given an integer array with all positive numbers and no duplicates, find the 
// number of possible combinations that add up to a positive integer target.

// nums = [1, 2, 3]
// target = 4

// The possible combination ways are:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)

// Note that different sequences are counted as different combinations.

// Therefore the output is 7.

#include "leetcode.hpp"

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // Complexity: exponential
        // if(target == 0) return 1;
        // if(target < 0)  return 0;
        // int n = 0;
        // for(int elem : nums)
        //     n += combinationSum4(nums, target - elem);
        // return n;
        
        vector<int> aux(target + 1, 0);
        aux[0] = 1;
        for(int i = 1; i <= target; ++i)
            for(int j = 0; j < nums.size(); ++j)
                if(i - nums[j] >= 0)
                    aux[i] += aux[i - nums[j]];
        return aux[target];
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> nums{1, 2, 3};
    CHECK_TRUE(sln.combinationSum4(nums, 4) == 7);
    TEST_REPORT();
}