// 539. Minimum Time Difference
// Given a list of 24-hour clock time points in "Hour:Minutes" format, find the 
// minimum minutes difference between any two time points in the list.

// Example 1:
// Input: ["23:59","00:00"]
// Output: 1

// Note:
// The number of time points in the given list is at least 2 and won't exceed 20000.
// The input time is legal and ranges from 00:00 to 23:59.

#include "leetcode.hpp"

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> ivec;
        ivec.reserve(timePoints.size());
        for(const auto& s : timePoints)
        {
            int val = (s[0] * 10 + s[1]) * 60 + s[3] * 10 + s[4];
            ivec.push_back(val);
        }
        sort(ivec.begin(), ivec.end());
        int res = 1440 - ivec.back() + ivec.front();
        for(size_t i = 1; i < ivec.size(); ++i)
            res = min(res, ivec[i] - ivec[i - 1]);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<string> timePoints1 = {"23:59", "00:00"};
    vector<string> timePoints2 = {"00:30", "01:20", "02:40", "05:30", "21:10", "22:00", "22:20"};
    CHECK_TRUE(sln.findMinDifference(timePoints1) == 1);
    CHECK_TRUE(sln.findMinDifference(timePoints2) == 20);
    TEST_REPORT();
}