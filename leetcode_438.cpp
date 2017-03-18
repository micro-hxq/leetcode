// 438. Find All Anagrams in a String

// Given a string s and a non-empty string p, find all the start indices of 
// p's anagrams in s.
// Strings consists of lowercase English letters only and the length of both 
// strings s and p will not be larger than 20,100.
// The order of output does not matter.

// Example 1:

// Input:
// s: "cbaebabacd" p: "abc"

// Output:
// [0, 6]

// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".
// Example 2:

// Input:
// s: "abab" p: "ab"

// Output:
// [0, 1, 2]

// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".

#include "leetcode.hpp"

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // Complexity: O(NM)
        // vector<int> res;
        // if(p.size() > s.size()) return res;
        // auto lenp = p.size(), lens = s.size();
        // int tab[26] = {0}, ptab[26] = {0};

        // for(size_t i = 0; i < lenp- 1; ++i)
        // {
        //     ++tab[s[i] - 'a'];
        //     ++ptab[p[i] - 'a'];
        // }
        // ++ptab[p.back() - 'a'];
        // for(size_t i = 0, j = lenp - 1; j < lens; ++i, ++j)
        // {
        //     ++tab[s[j] - 'a'];
        //     bool isAnagrams = true;
        //     for(char ch : p)
        //     {
        //         if(tab[ch - 'a'] != ptab[ch - 'a'])
        //         {
        //             isAnagrams = false;
        //             break;
        //         }
        //     }
        //     if(isAnagrams)
        //         res.push_back(i);
        //     --tab[s[i] - 'a'];
        // }
        // return res;
        
        vector<int> res;
        int tab[26] = {0};
        for(char c : p)
            ++tab[c - 'a'];
        int count = p.size(), len = p.size();
        for(size_t i = 0; i < s.size(); ++i)
        {
            if(--tab[s[i] - 'a'] >= 0)
                --count;
            int j = i - len + 1;
            if(count == 0)
                res.push_back(j);
            if(j >= 0 && ++tab[s[j] - 'a'] > 0)
                ++count;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;

    string s1 = "cbaebabacd", p1 = "abc";
    vector<int> ans1 = {0, 6};
    auto res1 = sln.findAnagrams(s1, p1);
    CHECK_TRUE(ans1.size() == res1.size());
    CHECK_TRUE(ans1 == res1);

    string s2 = "abab", p2 = "ab";
    vector<int> ans2 = {0, 1, 2};
    auto res2 = sln.findAnagrams(s2, p2);
    CHECK_TRUE(ans2.size() == res2.size());
    CHECK_TRUE(ans2 == res2);

    string s3 = "baa", p3 = "aa";
    vector<int> ans3 = {1};
    auto res3 = sln.findAnagrams(s3, p3);
    CHECK_TRUE(ans3.size() == res3.size());
    CHECK_TRUE(ans3 == res3);
    TEST_REPORT();
}