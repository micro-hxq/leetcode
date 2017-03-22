// 111. Minimum Depth of Binary Tree

// Given a binary tree, find its minimum depth.

// The minimum depth is the number of nodes along the shortest path from 
// the root node down to the nearest leaf node.

// Subscribe to see which companies asked this question.

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
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int res = INT_MAX;
        helper(res, 1, root);
        return res;
    }

    void helper(int& mindepth, int curdepth, TreeNode* root)
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            mindepth = curdepth;
            return;
        }
        if(curdepth < mindepth)
        {
            if(root->left)
                helper(mindepth, curdepth + 1, root->left);
            if(root->right)
                helper(mindepth, curdepth + 1, root->right);
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;

    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(5);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;

    CHECK_TRUE(sln.minDepth(n1) == 2);

    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;    

    TEST_REPORT();
}