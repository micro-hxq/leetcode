// 77. Combinations

// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

// For example,
// If n = 4 and k = 2, a solution is:

// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

#include "leetcode.hpp"

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> aux;
        helper(ans, aux, 1, n, k);
        return ans;
    }

    void helper(vector<vector<int>>& ans, vector<int>& aux, int cur, int n, int k)
    {
        for(int i = cur; i <= n; ++i)
        {
            if(n - i + 1 < k) break;
            aux.push_back(i);
            if(k == 1)
                ans.push_back(aux);
            else
                helper(ans, aux, i + 1, n, k - 1);
            aux.pop_back();
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<vector<int>> ans1 = {{2, 4}, {3, 4}, {2, 3}, {1, 2}, {1, 3}, {1, 4}};
    auto res1 = sln.combine(4, 2);
    sort(ans1.begin(), ans1.end());
    sort(res1.begin(), res1.end());
    cout << ans1.size() << " " << res1.size() << endl;
    CHECK_TRUE(ans1 == res1);

    TEST_REPORT();
}