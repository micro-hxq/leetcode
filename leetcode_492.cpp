// 492. Construct the Rectangle
// For a web developer, it is very important to know how to design a web page's 
// size. So, given a specific rectangular web page’s area, your job by now is to
// design a rectangular web page, whose length L and width W satisfy the following 
// requirements:
// 1. The area of the rectangular web page you designed must equal to the given target area.

// 2. The width W should not be larger than the length L, which means L >= W.

// 3. The difference between length L and width W should be as small as possible.

// You need to output the length L and the width W of the web page you designed in sequence.

// Example:
// Input: 4
// Output: [2, 2]
// Explanation: The target area is 4, and all the possible ways to construct it are [1,4], [2,2], [4,1]. 

#include "leetcode.hpp"

class Solution {
public:
    vector<int> constructRectangle(int area) {
        // for(int length = static_cast<int>(sqrt(area)); length <= area; ++length)
        // {
        //     int width = area / length;
        //     if(width <= length)
        //     {
        //         if(width * length == area)
        //             return {length, width};
        //     }
        // }
        // return {0, 0};
        int width = static_cast<int>(sqrt(area));
        while(area % width)
            --width;
        return {area / width, width};
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> ans = {2, 2};
    auto res = sln.constructRectangle(4);
    CHECK_TRUE(ans == res);
    TEST_REPORT();
}