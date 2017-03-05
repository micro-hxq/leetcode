// 205. Isomorphic Strings
// Given two strings s and t, determine if they are isomorphic.

// Two strings are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while 
// preserving the order of characters. No two characters may map to the same 
// character but a character may map to itself.

// For example,
// Given "egg", "add", return true.

// Given "foo", "bar", return false.

// Given "paper", "title", return true.

// Note:
// You may assume both s and t have the same length.

#include "leetcode.hpp"

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int tab1[128] = {0}, tab2[128] = {0};
        int cnt = 0;
        for(char c : s)
            if(tab1[c] == 0)
                tab1[c] = ++cnt;
        cnt = 0;
        for(char c : t)
            if(tab2[c] == 0)
                tab2[c] = ++cnt;
        for(size_t i = 0; i < s.size(); ++i)
            if(tab1[s[i]] != tab2[t[i]])
                return false;
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;

    CHECK_TRUE(sln.isIsomorphic("egg", "add"));
    CHECK_FALSE(sln.isIsomorphic("foo", "bar"));
    CHECK_TRUE(sln.isIsomorphic("paper", "title"));

    TEST_REPORT();
}