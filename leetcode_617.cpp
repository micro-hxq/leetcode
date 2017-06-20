// 617. Merge Two Binary Trees

// Given two binary trees and imagine that when you put one of them to 
// cover the other, some nodes of the two trees are overlapped while 
// the others are not.

// You need to merge them into a new binary tree. The merge rule is that 
// if two nodes overlap, then sum node values up as the new value of the 
// merged node. Otherwise, the NOT null node will be used as the node of new tree.

// Example 1:
// Input: 
//     Tree 1                     Tree 2                  
//           1                         2                             
//          / \                       / \                            
//         3   2                     1   3                        
//        /                           \   \                      
//       5                             4   7                  
// Output: 
// Merged tree:
//          3
//         / \
//        4   5
//       / \   \ 
//      5   4   7
// Note: The merging process must start from the root nodes of both trees.

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == nullptr && t2 == nullptr) return nullptr;
        int v1 = t1 == nullptr ? 0 : t1->val;
        int v2 = t2 == nullptr ? 0 : t2->val;
        TreeNode *t1l = nullptr, *t1r = nullptr, *t2l = nullptr, *t2r = nullptr;
        if(t1)
        {
            t1l = t1->left;
            t1r = t1->right;
        }
        if(t2)
        {
            t2l = t2->left;
            t2r = t2->right;
        }
        TreeNode *node = new TreeNode(v1 + v2);
        node->left = mergeTrees(t1l, t2l);
        node->right = mergeTrees(t1r, t2r);
        return node;
    }
};

class Validator {
public:
    static bool treeEqual(TreeNode* t1, TreeNode* t2)
    {
        if(t1 == nullptr || t2 == nullptr)  return t1 == t2;
        return t1->val == t2->val && treeEqual(t1->left, t2->left) && 
                treeEqual(t1->right, t2->right);
    }

};

int main(int argc, char const *argv[])
{
    Solution sln;
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);    
    TreeNode* n3 = new TreeNode(3);    
    TreeNode* n5 = new TreeNode(5);
    n1->left = n3;
    n1->right = n2;
    n3->left = n5;

    TreeNode* t1 = new TreeNode(1);
    TreeNode* t2 = new TreeNode(2);
    TreeNode* t3 = new TreeNode(3);
    TreeNode* t4 = new TreeNode(4);
    TreeNode* t7 = new TreeNode(7);
    t2->left = t1;
    t2->right = t3;
    t1->right = t4;
    t3->right = t7;

    TreeNode* r1 = new TreeNode(3);    
    TreeNode* r2 = new TreeNode(4);    
    TreeNode* r3 = new TreeNode(5);
    TreeNode* r4 = new TreeNode(5);
    TreeNode* r5 = new TreeNode(4);
    TreeNode* r6 = new TreeNode(7);
    r1->left = r2;
    r1->right = r3;
    r2->left = r4;
    r2->right = r5;
    r3->right = r6;

    CHECK_TRUE(Validator::treeEqual(sln.mergeTrees(n1, t2), r1));
    delete n1;    
    delete n2;    
    delete n3;
    delete n5;
    delete t1;
    delete t2;
    delete t3;
    delete t4;
    delete t7;
    delete r1;
    delete r2;
    delete r3;
    delete r4;
    delete r5;
    delete r6;
    TEST_REPORT();
}
