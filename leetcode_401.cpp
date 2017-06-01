// 401. Binary Watch

// A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 
// 6 LEDs on the bottom represent the minutes (0-59).

// Each LED represents a zero or one, with the least significant bit on the right.

// For example, the above binary watch reads "3:25".

// Given a non-negative integer n which represents the number of LEDs that are 
// currently on, return all possible times the watch could represent.

// Example:

// Input: n = 1
// Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]

// Note:
// The order of output does not matter.
// The hour must not contain a leading zero, for example "01:00" is not valid, it 
// should be "1:00".
// The minute must be consist of two digits and may contain a leading zero, for example 
// "10:2" is not valid, it should be "10:02".
// 
#include "leetcode.hpp"

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<int> aux(60);
        helper(aux);
        vector<string> res;
        for(int h = 0; h <= num; ++h)
        {
            if(h < 4 && num - h < 6)
            {
                vector<string> hour = hourToStr(aux, h);
                vector<string> minute = minuteToStr(aux, num - h);
                for(const auto& hh : hour)
                    for(const auto& mm : minute)
                        res.push_back(hh + ':' + mm);
            }
        }
        return res;
    }

    vector<string> hourToStr(vector<int>& aux, int h)
    {
        vector<string> res;
        for(size_t i = 0; i < 12; ++i)
            if(aux[i] == h) 
                res.push_back(to_string(i));
        return res;
    }
    vector<string> minuteToStr(vector<int>& aux, int m)
    {
        vector<string> res;
        for(size_t i = 0; i < aux.size(); ++i)
            if(aux[i] == m)
                res.push_back((i < 10 ? "0" : "") + to_string(i));
        return res;
    }

    void helper(vector<int>& aux)
    {
        for(int i = 0; i < 60; ++i)
        {
            int count = 0;
            int n = i;
            while(n != 0)
            {
                count += n & 1;
                n >>= 1;
            }
            aux[i] = count;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<string> ans1 = 
        {"1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"};
    auto res1 = sln.readBinaryWatch(1);
    sort(ans1.begin(), ans1.end());
    sort(res1.begin(), res1.end());
    CHECK_TRUE(ans1 == res1);

    vector<string> ans2 = {"0:00"};
    auto res2 = sln.readBinaryWatch(0);
    CHECK_TRUE(ans2 == res2);
    
    TEST_REPORT();
}