// 583. Delete Operation for Two Strings

// Given two words word1 and word2, find the minimum number of steps required to 
// make word1 and word2 the same, where in each step you can delete one character 
// in either string.

// Example 1:
// Input: "sea", "eat"
// Output: 2

// Explanation: You need one step to make "sea" to "ea" and another step to make 
// "eat" to "ea".

// Note:
// The length of given words won't exceed 500.
// Characters in given words can only be lower-case letters.


#include "leetcode.hpp"

class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.empty() || word2.empty()) return word1.size() + word2.size();
        int len1 = word1.size(), len2 = word2.size();
        vector<vector<int>> aux(len1 + 1, vector<int>(len2 + 1, 0));
        for(int i = 0; i < len1; ++i)
        {
            int ix = i + 1;
            for(int j = 0; j < len2; ++j)
            {
                int jx = j + 1;
                int maxval = max(aux[i][jx], aux[ix][j]);
                aux[ix][jx] = word1[i] == word2[j] ? (aux[i][j] + 1) : maxval;
            }
        }
        return len1 + len2 - 2 * aux[len1][len2];
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    
    CHECK_TRUE(sln.minDistance("sea", "eat") == 2);    
    CHECK_TRUE(sln.minDistance("abc", "xyz") == 6);
    CHECK_TRUE(sln.minDistance("intention", "execution") == 8);
    TEST_REPORT();
}
