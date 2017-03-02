// 318. Maximum Product of Word Lengths
// Given a string array words, find the maximum value of length(word[i]) * 
// length(word[j]) where the two words do not share common letters. You may 
// assume that each word will contain only lower case letters. If no such two 
// words exist, return 0.
// Example 1:
// Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
// Return 16
// The two words can be "abcw", "xtfn".

// Example 2:
// Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
// Return 4
// The two words can be "ab", "cd".

// Example 3:
// Given ["a", "aa", "aaa", "aaaa"]
// Return 0
// No such pair of words.

#include "leetcode.hpp"

class Solution {
public:
    int maxProduct(vector<string>& words) {
        bitset<26> bs;
        size_t res = 0;
        sort(words.begin(), words.end(),
            [](const string& s1, const string& s2) { return s1.size() > s2.size(); });
        for(auto cur = words.begin(); cur != words.end(); ++cur)
        {
            auto len1 = cur->size();
            if(len1 * len1 <= res)  break;
            for(char ch : *cur)
                bs.set(ch - 'a');
            for(auto iter = cur + 1; iter != words.end(); ++iter)
            {
                auto prod = iter->size() * len1;
                if(prod <= res)  break;
                auto sit = iter->begin();
                for(; sit != iter->end(); ++sit)
                    if(bs.test(*sit - 'a'))
                        break;
                if(sit == iter->end())
                    res = prod;
            }
            bs.reset();
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<string> words1 = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    vector<string> words2 = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
    vector<string> words3 = {"a", "aa", "aaa", "aaaa"};
    CHECK_TRUE(sln.maxProduct(words1) == 16);
    CHECK_TRUE(sln.maxProduct(words2) == 4);
    CHECK_TRUE(sln.maxProduct(words3) == 0);
    TEST_REPORT();
}