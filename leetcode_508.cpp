// 508. Most Frequent Subtree Sum

// Given the root of a tree, you are asked to find the most frequent subtree sum. 
// The subtree sum of a node is defined as the sum of all the node values formed 
// by the subtree rooted at that node (including the node itself). So what is the 
// most frequent subtree sum value? If there is a tie, return all the values with 
// the highest frequency in any order.

// Examples 1
// Input:

//   5
//  /  \
// 2   -3
// return [2, -3, 4], since all the values happen only once, return all of them in 
// any order.

// Examples 2
// Input:

//   5
//  /  \
// 2   -5
// return [2], since 2 happens twice, however -5 only occur once.

// Note: You may assume the sum of values in any subtree is in the range of 32-bit 
// signed integer.

#include "leetcode.hpp"


// Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> aux;
        int maxfreq = 0;
        treeSum(aux, maxfreq, root);
        vector<int> res;
        for(auto iter = aux.begin(); iter != aux.end(); ++iter)
        {
            if(iter->second == maxfreq)
                res.push_back(iter->first);
        }
        return res;
    }

    int treeSum(unordered_map<int, int>& m, int& maxfreq, TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        int vsum = root->val + treeSum(m, maxfreq, root->left) + treeSum(m, maxfreq, root->right);
        ++m[vsum];
        maxfreq = max(maxfreq, m[vsum]);
        return vsum;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    {
        TreeNode *n2 = new TreeNode(2);
        TreeNode *n5 = new TreeNode(5);
        TreeNode *nn3 = new TreeNode(-3);
        n5->left = n2;
        n5->right = nn3;
        vector<int> ans = {2, -3, 4};
        auto res = sln.findFrequentTreeSum(n5);
        CHECK_TRUE(ans.size() == res.size());
        sort(ans.begin(), ans.end());
        sort(res.begin(), res.end());
        CHECK_TRUE(ans == res);
        delete n2;
        delete n5;
        delete nn3;
    }
    {
        TreeNode *n2 = new TreeNode(2);
        TreeNode *n5 = new TreeNode(5);
        TreeNode *nn5 = new TreeNode(-5);
        n5->left = n2;
        n5->right = nn5;
        vector<int> ans = {2};
        auto res = sln.findFrequentTreeSum(n5);
        CHECK_TRUE(ans.size() == res.size());
        CHECK_TRUE(ans == res);
        delete n2;
        delete n5;
        delete nn5;
    }

    TEST_REPORT();
}