// 543. Diameter of Binary Tree

// Given a binary tree, you need to compute the length of the diameter of the tree. 
// The diameter of a binary tree is the length of the longest path between any two 
// nodes in a tree. This path may or may not pass through the root.

// Example:
// Given a binary tree 
//           1
//          / \
//         2   3
//        / \     
//       4   5    
// Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

// Note: The length of path between two nodes is represented by the number of edges 
// between them.

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
    int diameterOfBinaryTree(TreeNode* root) {
        int max = 0;
        helper(max, root);
        return max;
    }

    int helper(int& max, TreeNode* root)
    {
        if(root == nullptr) return 0;
        int hl = helper(max, root->left);
        int hr = helper(max, root->right);
        if(hl + hr > max)
            max = hl + hr;
        return (hl < hr ? hr : hl) + 1;
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

    CHECK_TRUE(sln.diameterOfBinaryTree(n1) == 3);

    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;

    TEST_REPORT();
}