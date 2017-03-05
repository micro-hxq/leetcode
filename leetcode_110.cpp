// 110. Balanced Binary Tree
// Given a binary tree, determine if it is height-balanced.

// For this problem, a height-balanced binary tree is defined as a binary tree in 
// which the depth of the two subtrees of every node never differ by more than 1.

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
    bool isBalanced(TreeNode* root) {
        bool res = true;
        helper(root, res);
        return res;   
    }

    int helper(TreeNode* node, bool& res)
    {
        if(node == nullptr) return 0;
        int hl = helper(node->left, res);
        int hr = helper(node->right, res);
        if(abs(hl - hr) > 1)
            res = false;
        return (hl < hr ? hr : hl) + 1;
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
        n1->left = n2;
        n1->right = n3;
        n2->right = n4;
        CHECK_TRUE(sln.isBalanced(n1));
        delete n1;
        delete n2;
        delete n3;
        delete n4;        
    }

    {
        TreeNode *n1 = new TreeNode(1);
        TreeNode *n2 = new TreeNode(2);
        TreeNode *n3 = new TreeNode(3);
        TreeNode *n4 = new TreeNode(4);
        n1->left = n2;
        n2->left = n4;
        n2->right = n3;
        CHECK_FALSE(sln.isBalanced(n1));
        delete n1;
        delete n2;
        delete n3;
        delete n4;        
    }

    TEST_REPORT();
}