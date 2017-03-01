// 216. Combination Sum III
// Find all possible combinations of k numbers that add up to a number n, given 
// that only numbers from 1 to 9 can be used and each combination should be a 
// unique set of numbers.
// Example 1:
// Input: k = 3, n = 7
// Output:
// [[1,2,4]]

// Example 2:
// Input: k = 3, n = 9
// Output:
// [[1,2,6], [1,3,5], [2,3,4]]

#include "leetcode.hpp"

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> aux;
        trace(res, aux, 1, k, n);
        return res;
    }

    void trace(vector<vector<int>>& res, vector<int>& aux, int num, int k, int target)
    {
        if(num > 9 || k < 1) return;
        if(k == 1)
        {
            if(target == num)
            {
                aux.push_back(num);
                res.push_back(aux);
                aux.pop_back();
                return;
            }
        }
        aux.push_back(num);
        trace(res, aux, num + 1, k - 1, target - num);
        aux.pop_back();
        trace(res, aux, num + 1, k, target);
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<vector<int>> ans1 = {{1, 2, 4}};
    auto res1 = sln.combinationSum3(3, 7);
    CHECK_TRUE(ans1.size() == res1.size());
    CHECK_TRUE(ans1 == res1);

    vector<vector<int>> ans2 = {{1, 2, 6}, {1, 3, 5}, {2, 3, 4}};
    auto res2 = sln.combinationSum3(3, 9);
    CHECK_TRUE(ans2.size() == res2.size());
    CHECK_TRUE(ans2 == res2);
    TEST_REPORT();
}