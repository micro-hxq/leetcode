// 496. Next Greater Element I
// You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

// The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

// Example 1:
// Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
// Output: [-1,3,-1]
// Explanation:
//     For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
//     For number 1 in the first array, the next greater number for it in the second array is 3.
//     For number 2 in the first array, there is no next greater number for it in the second array, so output -1.

// Example 2:
// Input: nums1 = [2,4], nums2 = [1,2,3,4].
// Output: [3,-1]
// Explanation:
//     For number 2 in the first array, the next greater number for it in the second array is 3.
//     For number 4 in the first array, there is no next greater number for it in the second array, so output -1.

#include "leetcode.hpp"

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        // Time Complexity: O(MN)
        vector<int> res;
        for(auto fiter = findNums.begin(); fiter != findNums.end(); ++fiter)
        {
            int findval = *fiter;
            auto siter = nums.begin();
            while(*siter++ != findval);
            for(; siter != nums.end(); ++siter)
            {
                if(findval < *siter)
                {
                    res.push_back(*siter);
                    break;
                }
            }
            if(siter == nums.end())
                res.push_back(-1);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> nums1 = {4, 1, 2}, nums2 = {1, 3, 4, 2};
    vector<int> ans1 = {-1, 3, -1};
    auto res1 = sln.nextGreaterElement(nums1, nums2);
    CHECK_TRUE(ans1.size() == res1.size());
    CHECK_TRUE(ans1 == res1);

    vector<int> nums3 = {2, 4}, nums4 = {1, 2, 3, 4};
    vector<int> ans2 = {3, -1};
    auto res2 = sln.nextGreaterElement(nums3, nums4);
    CHECK_TRUE(ans2.size() == res2.size());
    CHECK_TRUE(ans2 == res2);
    TEST_REPORT();
}