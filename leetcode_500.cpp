// 500. Keyboard Row
// Given a List of words, return the words that can be typed using letters of
// alphabet on only one row's of American keyboard like the image below.
// Example 1:
// Input: ["Hello", "Alaska", "Dad", "Peace"]
// Output: ["Alaska", "Dad"]

#include "leetcode.hpp"

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        static vector<int> tab = {2, 3, 3, 2, 1, 2, 2, 2, 1, 2,
                                  2, 2, 3, 3, 1, 1, 1, 1, 2, 1,
                                  1, 3, 1, 3, 1, 3};
        vector<string> res;
        for(const auto& s : words)
        {
            if(!s.empty())
            {
                int v1 = tab[s[0] < 'a' ? s[0] - 'A' : s[0] - 'a'];
                size_t i = 1;
                for(; i < s.size(); ++i)
                {
                    int v2 = tab[s[i] < 'a' ? s[i] - 'A' : s[i] - 'a'];
                    if(v1 != v2)
                        break;
                }
                if(i == s.size())
                    res.push_back(s);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};
    vector<string> ans = {"Alaska", "Dad"};
    auto res = sln.findWords(words);

    CHECK_TRUE(res.size() == ans.size());
    CHECK_TRUE(res == ans);
    TEST_REPORT();
}