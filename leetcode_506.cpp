// 506. Relative Ranks
// Given scores of N athletes, find their relative ranks and the people with the 
// top three highest scores, who will be awarded medals: "Gold Medal", "Silver 
// Medal" and "Bronze Medal".

// Example 1:
// Input: [5, 4, 3, 2, 1]
// Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
// Explanation: The first three athletes got the top three highest scores, so they 
// got "Gold Medal", "Silver Medal" and "Bronze Medal". For the left two athletes, 
// you just need to output their relative ranks according to their scores.

#include "leetcode.hpp"

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        size_t len = nums.size();
        vector<pair<size_t, int>> aux(len);
        for(size_t i = 0; i < len; ++i)
            aux[i] = make_pair(i, nums[i]);
        sort(aux.begin(), aux.end(), 
            [](const auto& v1, const auto& v2) { return v1.second > v2.second;});
        vector<string> res(len);
        if(len > 0) res[aux[0].first] = "Gold Medal";
        if(len > 1) res[aux[1].first] = "Silver Medal";
        if(len > 2) res[aux[2].first] = "Bronze Medal";
        for(size_t i = 3; i < len; ++i)
            res[aux[i].first] = to_string(i + 1);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> nums = {5, 4, 3, 2, 1};
    vector<string> ans = {"Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"};
    auto res = sln.findRelativeRanks(nums);

    CHECK_TRUE(ans.size() == res.size());
    CHECK_TRUE(ans == res);
    TEST_REPORT();
}