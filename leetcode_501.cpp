// 501. Find Mode in Binary Search Tree

// Given a binary search tree (BST) with duplicates, find all the mode(s) 
// (the most frequently occurred element) in the given BST.

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than or 
// equal to the node's key.
// The right subtree of a node contains only nodes with keys greater than 
// or equal to the node's key.
// Both the left and right subtrees must also be binary search trees.

// For example:
// Given BST [1,null,2,2],
//    1
//     \
//      2
//     /
//    2
// return [2].

// Note: If a tree has more than one mode, you can return them in any order.

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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int val, count = 0, maxCount = 0;
        helper(res, val, count, maxCount, root);
        return res;
    }

    void helper(vector<int>& res, int& val, int& count, int& maxCount, TreeNode* root)
    {
        if(root == nullptr)     return;
        helper(res, val, count, maxCount, root->left);
        count = val == root->val ? count + 1 : 1;
        if(count == maxCount)
            res.push_back(root->val);
        else if(count > maxCount)
        {
            res.clear();
            res.push_back(root->val);
            maxCount = count;
        }
        val = root->val;
        helper(res, val, count, maxCount, root->right);
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n21 = new TreeNode(2);
    TreeNode *n22 = new TreeNode(2);

    n1->right = n21;
    n21->left = n22;

    vector<int> ans = {2};
    auto res = sln.findMode(n1);
    CHECK_TRUE(res.size() == ans.size());
    CHECK_TRUE(res == ans);

    TEST_REPORT();
}