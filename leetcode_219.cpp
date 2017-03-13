// 219. Contains Duplicate II
// Given an array of integers and an integer k, find out whether there are two 
// distinct indices i and j in the array such that nums[i] = nums[j] and the 
// absolute difference between i and j is at most k.

#include "leetcode.hpp"

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> aux;
        int len = nums.size();
        bool res = false;

        for(int i = 0; i < len; ++i)
        {
            if(i > k)
                --aux[nums[i - k - 1]];
            if(aux[nums[i]])
                return true;
            else
                ++aux[nums[i]];
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    
    TEST_REPORT();
}