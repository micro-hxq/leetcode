// 107. Binary Tree Level Order Traversal II

// Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
// (ie, from left to right, level by level from leaf to root).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its bottom-up level order traversal as:
// [
//   [15,7],
//   [9,20],
//   [3]
// ]

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        helper(root, res, 0);
        reverse(res.begin(), res.end());
        return res;
    }
    void helper(TreeNode* root, vector<vector<int>>& res, int h)
    {
        if(root == nullptr) return;
        if(res.size() == h) res.push_back(vector<int>());
        helper(root->left, res, h + 1);
        helper(root->right, res, h + 1);
        res[h].push_back(root->val);
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    TreeNode *n3 = new TreeNode(3);    
    TreeNode *n9 = new TreeNode(9);
    TreeNode *n20 = new TreeNode(20);
    TreeNode *n15 = new TreeNode(15);    
    TreeNode *n7 = new TreeNode(7);
    n3->left = n9;
    n3->right = n20;
    n20->left = n15;
    n20->right = n7;
    vector<vector<int>> ans = {{15, 7}, {9, 20}, {3}};
    cout << res.size() << std::endl;
    CHECK_TRUE(ans.size() == res.size());
    CHECK_TRUE(ans == res);

    delete n3;
    delete n9;    
    delete n20;    
    delete n15;    
    delete n7;    

    TEST_REPORT();
}