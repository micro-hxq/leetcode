// 437. Path Sum III

// You are given a binary tree in which each node contains an integer value.

// Find the number of paths that sum to a given value.

// The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

// The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

// Example:

// root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

//       10
//      /  \
//     5   -3
//    / \    \
//   3   2   11
//  / \   \
// 3  -2   1

// Return 3. The paths that sum to 8 are:

// 1.  5 -> 3
// 2.  5 -> 2 -> 1
// 3. -3 -> 11

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
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr) return 0;
        int lres = pathSum(root->left, sum);
        int rres = pathSum(root->right, sum);
        int res = 0;
        helper(root, sum, res);
        return res + lres + rres;
    }
    void helper(TreeNode* root, int sum, int& res)
    {
        if(root == nullptr) return;
        sum -= root->val;
        res += sum == 0 ? 1 : 0;
        helper(root->left, sum, res);
        helper(root->right, sum, res);
    }

};

int main(int argc, char const *argv[])
{
    Solution sln;
    {
        TreeNode *n1 = new TreeNode(10);
        TreeNode *n2 = new TreeNode(5);
        TreeNode *n3 = new TreeNode(-3);
        TreeNode *n4 = new TreeNode(3);
        TreeNode *n5 = new TreeNode(2);
        TreeNode *n6 = new TreeNode(11);
        TreeNode *n7 = new TreeNode(3);
        TreeNode *n8 = new TreeNode(-2);
        TreeNode *n9 = new TreeNode(1);

        n1->left = n2;
        n1->right = n3;
        n2->left = n4;
        n2->right = n5;
        n3->right = n6;
        n4->left = n7;
        n4->right = n8;
        n5->right = n9;

        CHECK_TRUE(sln.pathSum(n1, 8) == 3);
        CHECK_TRUE(sln.pathSum(n1, 100) == 0);
        delete n1;
        delete n2;
        delete n3;
        delete n4;
        delete n5;
        delete n6;    
        delete n7;
        delete n8;    
        delete n9;
    }
    {
        TreeNode* n1 = new TreeNode(5);
        TreeNode* n2 = new TreeNode(4);
        TreeNode* n3 = new TreeNode(8);
        TreeNode* n4 = new TreeNode(11);
        TreeNode* n5 = new TreeNode(13);
        TreeNode* n6 = new TreeNode(4);
        TreeNode* n7 = new TreeNode(7);
        TreeNode* n8 = new TreeNode(2);
        TreeNode* n9 = new TreeNode(5);
        TreeNode* n10 = new TreeNode(1);        

        n1->left = n2;
        n1->right = n3;
        n2->left = n4;
        n3->left = n5;
        n3->right = n6;
        n4->left = n7;
        n4->right = n8;
        n6->left = n9;
        n6->right = n10;

        CHECK_TRUE(sln.pathSum(n1, 22) == 3);

        delete n1;
        delete n2;
        delete n3;
        delete n4;
        delete n5;
        delete n6;
        delete n7;
        delete n8;
        delete n9;
        delete n10;        
    }
    {
        TreeNode *n1 = new TreeNode(1);
        CHECK_TRUE(sln.pathSum(n1, 0) == 0);
        CHECK_TRUE(sln.pathSum(n1, 1) == 1);
        delete n1;
    }
    

    TEST_REPORT();
}