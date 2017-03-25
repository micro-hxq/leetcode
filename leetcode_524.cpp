// 524. Longest Word in Dictionary through Deleting

// Given a string and a string dictionary, find the longest string in the 
// dictionary that can be formed by deleting some characters of the given 
// string. If there are more than one possible results, return the longest 
// word with the smallest lexicographical order. If there is no possible 
// result, return the empty string.

// Example 1:
// Input:
// s = "abpcplea", d = ["ale","apple","monkey","plea"]
// Output: 
// "apple"

// Example 2:
// Input:
// s = "abpcplea", d = ["a","b","c"]
// Output: 
// "a"

// Note:
// All the strings in the input will only contain lower-case letters.
// The size of the dictionary won't exceed 1,000.
// The length of all the strings in the input won't exceed 1,000.

#include "leetcode.hpp"

//  This is solution to problem without order restriction
//  
// class Solution {
// public:
//     string findLongestWord(string s, vector<string>& d) {
//         vector<int> aux(26, 0);
//         for(char ch : s)
//             ++aux[ch - 'a'];
//         string res;
//         for(const string& word : d)
//         {
//             auto iter = word.begin();
//             for(; iter != word.end(); ++iter)
//             {
//                 if(aux[*iter - 'a'] == 0)
//                     break;
//                 --aux[*iter - 'a'];
//             }
//             if(iter == word.end())
//             {
//                 if(res.size() == word.size())
//                     res = res < word ? res : word;
//                 else
//                     res = res.size() < word.size() ? word : res;
//             }
//             for(auto cur = word.begin(); cur != iter; ++cur)
//                 ++aux[*cur - 'a'];
//         }
//         return res;
//     }
// };

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res;
        for(const string& word : d)
        {
            auto it = word.begin();
            for(auto siter = s.begin(); it != word.end() && siter != s.end(); ++siter)
                if(*it == *siter)
                    ++it;
            if(it == word.end())
            {
                if(res.size() == word.size())
                    res = res <  word ? res : word;
                else
                    res = res.size() < word.size() ? word : res;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    string s1 = "abpcplea";
    vector<string> d1 = {"ale","apple","monkey","plea"};
    CHECK_TRUE(sln.findLongestWord(s1, d1) == "apple");

    string s2 = "abpcplea";
    vector<string> d2 = {"a","b","c"};
    CHECK_TRUE(sln.findLongestWord(s2, d2) == "a");

    TEST_REPORT();
}