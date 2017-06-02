// 119. Pascal's Triangle II
// Given an index k, return the kth row of the Pascal's triangle.

// For example, given k = 3,
// Return [1,3,3,1].

// Note:
// Could you optimize your algorithm to use only O(k) extra space?
// 
#include "leetcode.hpp"

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int half = (rowIndex >> 1) + 1;
        vector<int> res(rowIndex + 1, 1);
        int dominator = 1, numerator = rowIndex;
        long num = 1;
        for(int i = 1; i < half; ++i)
        {
            num = (num * numerator) / dominator;
            res[i] = num;
            --numerator;
            ++dominator;
        }
        for(auto fit = res.begin(), bit = res.end() - 1; fit < bit; ++fit, --bit)
            *bit = *fit;
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> ans1 = {1};
    CHECK_TRUE(sln.getRow(0) == ans1);
    vector<int> ans2 = {1, 1};
    CHECK_TRUE(sln.getRow(1) == ans2);
    vector<int> ans3 = {1, 3, 3, 1};
    CHECK_TRUE(sln.getRow(3) == ans3);
    vector<int> ans4 = {1, 2, 1};
    CHECK_TRUE(sln.getRow(2) == ans4);
    TEST_REPORT();
}