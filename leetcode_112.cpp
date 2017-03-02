// 112. Path Sum
// Given a binary tree and a sum, determine if the tree has a root-to-leaf 
// path such that adding up all the values along the path equals the given sum.

// For example:
// Given the below binary tree and sum = 22,

//           5
//          / \
//         4   8
//        /   / \
//       11  13  4
//      /  \      \
//     7    2      1
// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr) return false;
        if(root->left == nullptr && root->right == nullptr)
            return sum == root->val;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }

};

int main(int argc, char const *argv[])
{
    Solution sln;
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node4_1 = new TreeNode(4);
    TreeNode *node8 = new TreeNode(8);
    TreeNode *node11 = new TreeNode(11);
    TreeNode *node13 = new TreeNode(13);
    TreeNode *node4_2 = new TreeNode(4);
    TreeNode *node7 = new TreeNode(7);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node1 = new TreeNode(1);
    node5->left = node4_1;
    node5->right = node8;
    node4_1->left = node11;
    node8->left = node13;
    node8->right = node4_2;
    node11->left = node7;
    node11->right = node2;
    node4_2->right = node1;

    CHECK_TRUE(sln.hasPathSum(node5, 22));

    delete node5;
    delete node4_1;
    delete node8;
    delete node11;
    delete node13;
    delete node4_2;
    delete node7;
    delete node2;
    delete node1;
    TEST_REPORT();
}