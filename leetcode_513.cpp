// 513. Find Bottom Left Tree Value

// Given a binary tree, find the leftmost value in the last row of the tree.

// Example 1:
// Input:

//     2
//    / \
//   1   3

// Output:
// 1
// Example 2: 
// Input:

//         1
//        / \
//       2   3
//      /   / \
//     4   5   6
//        /
//       7

// Output:
// 7
// Note: You may assume the tree (i.e., the given root node) is not NULL.

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
    int findBottomLeftValue(TreeNode* root) {
        int res = 0, maxh = 0;
        helper(res, maxh, root, 1);
        return res;
    }

    void helper(int& res, int& maxh, TreeNode* root, int h)
    {
        if(root == nullptr)
            return;
        if(h > maxh)
        {
            maxh = h;
            res = root->val;
        }
        helper(res, maxh, root->left, h + 1);
        helper(res, maxh, root->right, h + 1);
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    {
        TreeNode *n1 = new TreeNode(1);
        TreeNode *n2 = new TreeNode(2);
        TreeNode *n3 = new TreeNode(3);
        n2->left = n1;
        n2->right = n3;
        CHECK_TRUE(sln.findBottomLeftValue(n2) == 1);
        delete n1;
        delete n2;
        delete n3;
    }
    {
        TreeNode *n1 = new TreeNode(1);
        TreeNode *n2 = new TreeNode(2);    
        TreeNode *n3 = new TreeNode(3);    
        TreeNode *n4 = new TreeNode(4);    
        TreeNode *n5 = new TreeNode(5);    
        TreeNode *n6 = new TreeNode(6);    
        TreeNode *n7 = new TreeNode(7);    
        n1->left = n2;
        n1->right = n3;
        n2->left = n4;
        n3->left = n5;
        n3->right = n6;
        n5->left = n7;
        CHECK_TRUE(sln.findBottomLeftValue(n1) == 7);
        delete n1;
        delete n2;    
        delete n3;    
        delete n4;    
        delete n5;    
        delete n6;    
        delete n7;    
    }
    TEST_REPORT();
}