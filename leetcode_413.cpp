// 413. Arithmetic Slices

// A sequence of number is called arithmetic if it consists of at least three elements 
// and if the difference between any two consecutive elements is the same.

// For example, these are arithmetic sequence:

// 1, 3, 5, 7, 9
// 7, 7, 7, 7
// 3, -1, -5, -9
// The following sequence is not arithmetic.

// 1, 1, 2, 5, 7

// A zero-indexed array A consisting of N numbers is given. A slice of that array is any 
// pair of integers (P, Q) such that 0 <= P < Q < N.

// A slice (P, Q) of array A is called arithmetic if the sequence:
// A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

// The function should return the number of arithmetic slices in the array A.


// Example:

// A = [1, 2, 3, 4]

// return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.

#include "leetcode.hpp"

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3) return 0;
        int dist = A[1] - A[0], num = 0, res = 0;
        for(size_t i = 2; i < A.size(); ++i)
        {
            int cur_dist = A[i] - A[i - 1];
            if(cur_dist == dist)
            {
                ++num;
                res += num;
            }
            else
            {
                dist = cur_dist;
                num = 0;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> nums = {1, 2, 3, 4};
    CHECK_TRUE(sln.numberOfArithmeticSlices(nums) == 3);
    vector<int> nums2 = {1, 3, 5, 7, 9};
    CHECK_TRUE(sln.numberOfArithmeticSlices(nums2) == 6);
    vector<int> nums3 = {1, 1, 2, 5, 7};
    CHECK_TRUE(sln.numberOfArithmeticSlices(nums3) == 0);

    TEST_REPORT();
}