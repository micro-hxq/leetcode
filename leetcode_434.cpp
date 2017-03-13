// 434. Number of Segments in a String
// Count the number of segments in a string, where a segment is defined to be a 
// contiguous sequence of non-space characters.

// Please note that the string does not contain any non-printable characters.

// Example:

// Input: "Hello, my name is John"
// Output: 5


#include "leetcode.hpp"

class Solution {
public:
    int countSegments(string s) {

        // istringstream strm(s);
        // string temp;
        // int res = 0;
        // while(strm >> temp)
        //     ++res;
        // return res;
        
        if(s.empty())   return 0;
        int res = 0;
        auto iter = s.begin();
        while(iter != s.end() && isspace(*iter))
            ++iter;
        while(iter != s.end())
        {
            if(isspace(*iter))
            {
                ++res;
                while(++iter != s.end() && isspace(*iter));
            }
            else
                ++iter;
        }
        res = isspace(s.back()) ? res : res + 1;
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    CHECK_TRUE(sln.countSegments("hello") == 1);
    CHECK_TRUE(sln.countSegments("Hello, my name is John") == 5);
    CHECK_TRUE(sln.countSegments("  ") == 0);
    CHECK_TRUE(sln.countSegments(" hello     world   !") == 3);
    TEST_REPORT();
}
