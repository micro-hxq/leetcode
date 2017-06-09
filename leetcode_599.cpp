// 599. Minimum Index Sum of Two Lists

// Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a 
// list of favorite restaurants represented by strings.

// You need to help them find out their common interest with the least list index sum. 
// If there is a choice tie between answers, output all of them with no order requirement. 
// You could assume there always exists an answer.

// Example 1:
// Input:
// ["Shogun", "Tapioca Express", "Burger King", "KFC"]
// ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
// Output: ["Shogun"]

// Explanation: The only restaurant they both like is "Shogun".

// Example 2:
// Input:
// ["Shogun", "Tapioca Express", "Burger King", "KFC"]
// ["KFC", "Shogun", "Burger King"]
// Output: ["Shogun"]

// Explanation: The restaurant they both like and have the least index sum is "Shogun" 
// with index sum 1 (0+1).
// Note:
// The length of both lists will be in the range of [1, 1000].
// The length of strings in both lists will be in the range of [1, 30].
// The index is starting from 0 to the list length minus 1.
// No duplicates in both lists.

#include "leetcode.hpp"

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        size_t sum = list1.size() + list2.size();
        for(size_t i = 0; i < list1.size(); ++i)
        {
            for(size_t j = 0; i + j <= sum && j < list2.size(); ++j)
            {
                if(list1[i] == list2[j])
                {
                    if(i + j != sum)
                    {
                        sum = i + j;
                        ans.clear();
                    }
                    ans.push_back(list1[i]);
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    vector<string> andy = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> doris = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    vector<string> ans1 = {"Shogun"};
    CHECK_TRUE(sln.findRestaurant(andy, doris) == ans1);

    vector<string> andy2 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> doris2 = {"KFC", "Shogun", "Burger King"};
    vector<string> ans2 = {"Shogun"};
    CHECK_TRUE(sln.findRestaurant(andy2, doris2) == ans2);

    TEST_REPORT();
}
