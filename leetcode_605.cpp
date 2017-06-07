// 605. Can Place Flowers

// Suppose you have a long flowerbed in which some of the plots are planted and some 
// are not. However, flowers cannot be planted in adjacent plots - they would compete 
// for water and both would die.

// Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty 
//     and 1 means not empty), and a number n, return if n new flowers can be planted 
// in it without violating the no-adjacent-flowers rule.

// Example 1:
// Input: flowerbed = [1,0,0,0,1], n = 1
// Output: True

// Example 2:
// Input: flowerbed = [1,0,0,0,1], n = 2
// Output: False

// Note:
// The input array won't violate no-adjacent-flowers rule.
// The input array size is in the range of [1, 20000].
// n is a non-negative integer which won't exceed the input array size.

#include "leetcode.hpp"

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int prev = 0, ans = 0;
        for(size_t i = 0; i < flowerbed.size(); ++i)
        {
            if(prev == 0)
            {
                prev = 1;
                ans += flowerbed[i] == 0;
                if(ans > n) return true;
            }
            else
            {
                prev = flowerbed[i];
                ans -= prev == 1;
            }
        }
        return ans >= n;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> bed1 = { 1, 0, 0, 0, 1};
    CHECK_TRUE(sln.canPlaceFlowers(bed1, 1));
    CHECK_FALSE(sln.canPlaceFlowers(bed1, 2));

    vector<int> bed2 = {0};
    CHECK_TRUE(sln.canPlaceFlowers(bed2, 1));
    vector<int> bed3 = {1};
    CHECK_TRUE(sln.canPlaceFlowers(bed3, 0));
    vector<int> bed4 = {0, 1, 0};
    CHECK_TRUE(sln.canPlaceFlowers(bed4, 0));

    TEST_REPORT();
}