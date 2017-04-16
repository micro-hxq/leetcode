// 551. Student Attendance Record I
// You are given a string representing an attendance record for 
// a student. The record only contains the following three characters:

// 'A' : Absent.
// 'L' : Late.
// 'P' : Present.
// A student could be rewarded if his attendance record doesn't contain 
// more than one 'A' (absent) or more than two continuous 'L' (late).

// You need to return whether the student could be rewarded according to 
// his attendance record.

// Example 1:
// Input: "PPALLP"
// Output: True
// Example 2:
// Input: "PPALLL"
// Output: False

#include "leetcode.hpp"

class Solution {
public:
    bool checkRecord(string s) {
        int anum = 0, lnum = 0;
        for(char ch : s)
        {
            if(ch == 'A')
            {
                lnum = 0;
                if(++anum == 2)   return false;
            }
            else if(ch == 'L')
            {
                if(++lnum == 3)   return false;
            }
            else
            {
                lnum = 0;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    
    CHECK_TRUE(sln.checkRecord("PPALLP"));
    CHECK_FALSE(sln.checkRecord("PPALLL"));

    TEST_REPORT();
}