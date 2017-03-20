// 447. Number of Boomerangs

// Given n points in the plane that are all pairwise distinct, a "boomerang" 
// is a tuple of points (i, j, k) such that the distance between i and j equals 
// the distance between i and k (the order of the tuple matters).

// Find the number of boomerangs. You may assume that n will be at most 500 and 
// coordinates of points are all in the range [-10000, 10000] (inclusive).

// Example:
// Input:
// [[0,0],[1,0],[2,0]]

// Output:
// 2

// Explanation:
// The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]

#include "leetcode.hpp"

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        unordered_map<int, int> aux;
        int res = 0;
        for(const auto& p1 : points)
        {
            for(const auto& p2 : points)
            {
                int x = p1.first - p2.first;
                int y = p1.second - p2.second;
                ++aux[x * x + y * y];
            }
            for(const auto& elem : aux)
            {
                if(elem.second > 1)
                    res += elem.second * (elem.second - 1);
            }
            aux.clear();
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<pair<int, int>> points = {{0, 0}, {1, 0}, {2, 0}};
    CHECK_TRUE(sln.numberOfBoomerangs(points) == 2);

    TEST_REPORT();
}