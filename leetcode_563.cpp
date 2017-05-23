// 563. Binary Tree Tilt
// Given a binary tree, return the tilt of the whole tree.

// The tilt of a tree node is defined as the absolute difference between the sum 
// of all left subtree node values and the sum of all right subtree node values. 
// Null node has tilt 0.

// The tilt of the whole tree is defined as the sum of all nodes' tilt.

// Example:
// Input: 
//          1
//        /   \
//       2     3
// Output: 1

// Explanation: 
// Tilt of node 2 : 0
// Tilt of node 3 : 0
// Tilt of node 1 : |2-3| = 1
// Tilt of binary tree : 0 + 0 + 1 = 1

// Note:
// The sum of node values in any subtree won't exceed the range of 32-bit integer.
// All the tilt values won't exceed the range of 32-bit integer.

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
    int findTilt(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
    int helper(TreeNode* root, int& res)
    {
        if(root == nullptr) return 0;
        int sl = helper(root->left, res);
        int sr = helper(root->right, res);
        res += abs(sl - sr);
        return sl + sr + root->val;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    {
        TreeNode *n1 = new TreeNode(1);    
        TreeNode *n2 = new TreeNode(2);    
        TreeNode *n3 = new TreeNode(3);
        n1->left = n2;
        n1->right = n3;
        CHECK_TRUE(sln.findTilt(n1) == 1);
        delete n1;
        delete n2;
        delete n3;        
    }
    {
        TreeNode *n1 = nullptr;
        CHECK_TRUE(sln.findTilt(n1) == 0);
    }
    {
        TreeNode *n1 = new TreeNode(1);
        TreeNode *n2 = new TreeNode(2);
        TreeNode *n3 = new TreeNode(3);
        TreeNode *n4 = new TreeNode(4);
        TreeNode *n5 = new TreeNode(5);
        n1->left = n2;
        n1->right = n3;
        n2->left = n4;
        n3->left = n5;
        CHECK_TRUE(sln.findTilt(n1) == 11);
        delete n1;        
        delete n2;        
        delete n3;
        delete n4;
        delete n5;
    }
    TEST_REPORT();
}