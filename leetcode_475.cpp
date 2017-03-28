// 475. Heaters

// Winter is coming! Your first job during the contest is to design a standard 
// heater with fixed warm radius to warm all the houses.

// Now, you are given positions of houses and heaters on a horizontal line, find 
// out minimum radius of heaters so that all houses could be covered by those heaters.

// So, your input will be the positions of houses and heaters seperately, and your 
// expected output will be the minimum radius standard of heaters.

// Note:
// Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
// Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
// As long as a house is in the heaters' warm radius range, it can be warmed.
// All the heaters follow your radius standard and the warm radius will the same.

// Example 1:
// Input: [1,2,3],[2]
// Output: 1
// Explanation: The only heater was placed in the position 2, and if we use the radius 1 
// standard, then all the houses can be warmed.

// Example 2:
// Input: [1,2,3,4],[1,4]
// Output: 1
// Explanation: The two heater was placed in the position 1 and 4. We need to use radius 
// 1 standard, then all the houses can be warmed.

#include "leetcode.hpp"

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int res = 0;
        for(int pos : houses)
        {
            auto iter = lower_bound(heaters.begin(), heaters.end(), pos);
            if(iter == heaters.end())
                res = max(res, pos - heaters.back());
            else if(iter == heaters.begin())
                res = max(res, heaters.front() - pos);
            else
                res = max(res, min(pos - *(iter - 1), *iter - pos));
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> house1 = {1, 2, 3};
    vector<int> heater1 = {2};
    CHECK_TRUE(sln.findRadius(house1, heater1) == 1);

    vector<int> house2 = {1, 2, 3, 4};
    vector<int> heater2 = {1, 4};
    CHECK_TRUE(sln.findRadius(house2, heater2) == 1);
    TEST_REPORT();
}