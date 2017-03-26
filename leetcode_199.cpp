// 199. Binary Tree Right Side View

// Given a binary tree, imagine yourself standing on the right side of 
// it, return the values of the nodes you can see ordered from top to bottom.

// For example:
// Given the following binary tree,
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---
// You should return [1, 3, 4].

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        int maxh = 0;
        helper(res, maxh, 1, root);
        return res;
    }

    void helper(vector<int>& res, int& maxh, int h, TreeNode* root)
    {
        if(root == nullptr) return;
        if(h > maxh)
        {
            res.push_back(root->val);
            maxh = h;
        }
        helper(res, maxh, h + 1, root->right);
        helper(res, maxh, h + 1, root->left);
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    {
        TreeNode *n1 = new TreeNode(1);
        TreeNode *n2 = new TreeNode(2);
        TreeNode *n3 = new TreeNode(3);
        TreeNode *n4 = new TreeNode(4);
        TreeNode *n5 = new TreeNode(5);
        
        n1->left = n2;
        n1->right = n3;
        n2->right = n5;
        n3->right = n4;

        vector<int> ans = {1, 3, 4};
        CHECK_TRUE(sln.rightSideView(n1) == ans);

        delete n1;
        delete n2;        
        delete n3;
        delete n4;
        delete n5;
    }

    {
        TreeNode *n1 = new TreeNode(1);
        TreeNode *n2 = new TreeNode(2);
        TreeNode *n3 = new TreeNode(3);
        TreeNode *n5 = new TreeNode(5);
        
        n1->left = n2;
        n1->right = n3;
        n2->right = n5;

        vector<int> ans = {1, 3, 5};
        CHECK_TRUE(sln.rightSideView(n1) == ans);

        delete n1;
        delete n2;        
        delete n3;
        delete n5;
    }

    TEST_REPORT();
}