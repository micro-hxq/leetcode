// 88. Merge Sorted Array
// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

// Note:
// You may assume that nums1 has enough space (size that is greater or equal to 
// m + n) to hold additional elements from nums2. The number of elements initialized in 
// nums1 and nums2 are m and n respectively.

#include "leetcode.hpp"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int cur = m + n - 1;
        for(--m, --n; m >=0 && n >= 0; --cur)
        {
            if(nums1[m] > nums2[n])
                nums1[cur] = nums1[m--];
            else
                nums1[cur] = nums2[n--];
        }
        if(m == -1)
            copy(nums2.begin(), nums2.begin() + n + 1, nums1.begin());
    }
};


int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> nums1 {1, 3, 5, 7, 9};
    nums1.resize(10);
    vector<int> nums2 {0, 2, 4, 6, 8};
    vector<int> ans = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    sln.merge(nums1, 5, nums2, 5);
    CHECK_TRUE(ans.size() == nums1.size());
    CHECK_TRUE(ans == nums1);
    TEST_REPORT();
}