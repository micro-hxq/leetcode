// 394. Decode String
// Given an encoded string, return it's decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the 
// square brackets is being repeated exactly k times. Note that k is guaranteed 
// to be a positive integer.

// You may assume that the input string is always valid; No extra white spaces, 
// square brackets are well-formed, etc.

// Furthermore, you may assume that the original data does not contain any digits 
// and that digits are only for those repeat numbers, k. For example, there won't 
// be input like 3a or 2[4].

// Examples:

// s = "3[a]2[bc]", return "aaabcbc".
// s = "3[a2[c]]", return "accaccacc".
// s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

#include "leetcode.hpp"

class Solution {
public:
    string decodeString(string s) {
        stack<string> str_st;
        stack<int> num_st;
        str_st.push(string());
        for(const char *cur = s.c_str(); *cur; ++cur)
        {
            if(isalpha(*cur))
                str_st.top().push_back(*cur);
            else if(*cur == ']')
            {
                string aux_str;
                string cur_str = str_st.top();
                str_st.pop();
                int n = num_st.top();
                num_st.pop();
                for(int i = 0; i < n; ++i)
                    aux_str += cur_str;
                str_st.top().insert(str_st.top().end(), aux_str.begin(), aux_str.end());
            }
            else
            {
                char *str_end;
                int n = strtol(cur, &str_end, 10);
                cur = str_end;
                num_st.push(n);
                str_st.push(string());
            }
        }
        return str_st.top();
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    CHECK_TRUE(sln.decodeString("3[a]2[bc]") == "aaabcbc");
    CHECK_TRUE(sln.decodeString("3[a2[c]]") == "accaccacc");
    CHECK_TRUE(sln.decodeString("2[abc]3[cd]ef") == "abcabccdcdcdef");
    TEST_REPORT();
}
