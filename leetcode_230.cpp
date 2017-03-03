// 230. Kth Smallest Element in a BST
// Given a binary search tree, write a function kthSmallest to find the kth 
// smallest element in it.

// Note: 
// You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

// Follow up:
// What if the BST is modified (insert/delete operations) often and you need 
// to find the kth smallest frequently? How would you optimize the kthSmallest routine?
// Hint:

// 1. Try to utilize the property of a BST.
// 2. What if you could modify the BST node's structure?
// 3. The optimal runtime complexity is O(height of BST).

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
    int kthSmallest(TreeNode* root, int k) {
        int res = 0, idx = 0;
        traverse(res, root, k, idx);
        return res;
    }

    bool traverse(int& res, TreeNode* root, int k, int& idx)
    {
        if(root == nullptr) return false;
        if(traverse(res, root->left, k, idx))
            return true;
        if(++idx == k)
        {
            res = root->val;
            return true;
        }
        return traverse(res, root->right, k, idx);
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    TreeNode  *n1 = new TreeNode(1);
    TreeNode  *n2 = new TreeNode(2);
    TreeNode  *n3 = new TreeNode(3);
    TreeNode  *n4 = new TreeNode(4);
    TreeNode  *n5 = new TreeNode(5);
    TreeNode  *n6 = new TreeNode(6);
    TreeNode  *n7 = new TreeNode(7);

    n4->left = n2;
    n4->right = n6;
    n2->left = n1;
    n2->right = n3;
    n6->left = n5;
    n6->right = n7;

    CHECK_TRUE(sln.kthSmallest(n4, 1) == 1);
    CHECK_TRUE(sln.kthSmallest(n4, 2) == 2);
    CHECK_TRUE(sln.kthSmallest(n4, 3) == 3);
    CHECK_TRUE(sln.kthSmallest(n4, 4) == 4);
    CHECK_TRUE(sln.kthSmallest(n4, 5) == 5);
    CHECK_TRUE(sln.kthSmallest(n4, 6) == 6);
    CHECK_TRUE(sln.kthSmallest(n4, 7) == 7);

    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;
    delete n7;
    TEST_REPORT();
}