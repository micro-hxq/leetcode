// 96. Unique Binary Search Trees

// Given n, how many structurally unique BST's (binary search trees) 
// that store values 1...n?

// For example,
// Given n = 3, there are a total of 5 unique BST's.

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

#include "leetcode.hpp"

class Solution {
public:
    int numTrees(int n) {
        vector<int> aux(n + 1, 1);
        for(int i = 2; i <= n; ++i)
        {
            int sum = 0;
            for(int j = 1; j <= i; ++j)
            {
                int left = j - 1;
                int right = i - j;
                sum += aux[left] * aux[right];
            }
            aux[i] = sum;
        }
        return aux.back();
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;

    CHECK_TRUE(sln.numTrees(1) == 1);
    CHECK_TRUE(sln.numTrees(2) == 2);
    CHECK_TRUE(sln.numTrees(3) == 5);

    TEST_REPORT();
}