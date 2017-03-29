// 520. Detect Capital

// Given a word, you need to judge whether the usage of capitals in it is right or not.

// We define the usage of capitals in a word to be right when one of the following cases holds:

// All letters in this word are capitals, like "USA".
// All letters in this word are not capitals, like "leetcode".
// Only the first letter in this word is capital if it has more than one letter, like "Google".
// Otherwise, we define that this word doesn't use capitals in a right way.
// Example 1:
// Input: "USA"
// Output: True
// Example 2:
// Input: "FlaG"
// Output: False
// Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.

#include "leetcode.hpp"

class Solution {
public:
    bool detectCapitalUse(string word) {
        // auto cur = word.begin();
        // if(isupper(*cur))
        // {
        //     if(++cur != word.end())
        //     {
        //         if(isupper(*cur))
        //         {
        //             for(++cur; cur != word.end(); ++cur)
        //                 if(!isupper(*cur))
        //                     break;
        //         }
        //         else
        //         {
        //             for(++cur; cur != word.end(); ++cur)
        //                 if(!islower(*cur))
        //                     break;
        //         }
        //     }
        // }
        // else
        // {
        //     for(++cur; cur != word.end(); ++cur)
        //         if(!islower(*cur))
        //             break;
        // }
        // return cur == word.end();
        size_t upcount = 0;
        for(char ch : word)
            upcount += isupper(ch) ? 1 : 0;
        return upcount == 0 || upcount == word.size() || (upcount == 1 && isupper(word.front()));
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    CHECK_TRUE(sln.detectCapitalUse("A"));
    CHECK_TRUE(sln.detectCapitalUse("USA"));
    CHECK_TRUE(sln.detectCapitalUse("Google"));
    CHECK_TRUE(sln.detectCapitalUse("hello"));
    CHECK_TRUE(sln.detectCapitalUse("a"));
    CHECK_FALSE(sln.detectCapitalUse("FlaG"));

    TEST_REPORT();
}