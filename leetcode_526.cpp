// 526. Beautiful Arrangement

// Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array 
// that is constructed by these N numbers successfully if one of the following is true for 
// the ith position (1 ≤ i ≤ N) in this array:

// The number at the ith position is divisible by i.
// i is divisible by the number at the ith position.
// Now given N, how many beautiful arrangements can you construct?

// Example 1:
// Input: 2
// Output: 2
// Explanation: 

// The first beautiful arrangement is [1, 2]:

// Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).

// Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).

// The second beautiful arrangement is [2, 1]:

// Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).

// Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
// Note:
// N is a positive integer and will not exceed 15.

#include "leetcode.hpp"

class Solution {
public:
    int countArrangement(int N) {
        vector<int> nums(N);
        iota(nums.begin(), nums.end(), 1);
        return helper(N, nums);
    }
    int helper(int n, vector<int>& aux)
    {
        if(n == 1) return 1;
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            if(aux[i] % n == 0 || n % aux[i] == 0)
            {
                swap(aux[i], aux[n - 1]);
                res += helper(n - 1, aux);
                swap(aux[i], aux[n - 1]);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    CHECK_TRUE(sln.countArrangement(1) == 1);
    CHECK_TRUE(sln.countArrangement(2) == 2);
    CHECK_TRUE(sln.countArrangement(3) == 3);
    CHECK_TRUE(sln.countArrangement(4) == 8);
    CHECK_TRUE(sln.countArrangement(5) == 10);
    CHECK_TRUE(sln.countArrangement(6) == 36);
    TEST_REPORT();
}