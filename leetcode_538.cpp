// 538. Convert BST to Greater Tree
// Given a Binary Search Tree (BST), convert it to a Greater Tree such that every 
// key of the original BST is changed to the original key plus sum of all keys greater 
// than the original key in BST.

// Example:

// Input: The root of a Binary Search Tree like this:
//               5
//             /   \
//            2     13

// Output: The root of a Greater Tree like this:
//              18
//             /   \
//           20     13

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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        rightSonSum(sum, root);
        return root;
    }

    void rightSonSum(int& sum, TreeNode* root)
    {
        if(root == nullptr) return;
        rightSonSum(sum, root->right);
        sum += root->val;
        root->val = sum;
        rightSonSum(sum, root->left);
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;

    TreeNode *n2 = new TreeNode(2);
    TreeNode *n5 = new TreeNode(5);    
    TreeNode *n13 = new TreeNode(13);

    n5->left = n2;
    n5->right = n13;

    n5 = sln.convertBST(n5); 

    CHECK_TRUE(n5->val == 18);
    CHECK_TRUE(n5->left->val == 20);
    CHECK_TRUE(n5->right->val == 13);

    delete n2;
    delete n5;
    delete n13;    

    TEST_REPORT();
}