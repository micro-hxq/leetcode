// 572. Subtree of Another Tree
// Given two non-empty binary trees s and t, check whether tree t has exactly the 
// same structure and node values with a subtree of s. A subtree of s is a tree 
// consists of a node in s and all of this node's descendants. The tree s could 
// also be considered as a subtree of itself.

// Example 1:
// Given tree s:

//      3
//     / \
//    4   5
//   / \
//  1   2
// Given tree t:
//    4 
//   / \
//  1   2
// Return true, because t has the same structure and node values with a subtree of s.

// Example 2:
// Given tree s:

//      3
//     / \
//    4   5
//   / \
//  1   2
//     /
//    0
// Given tree t:
//    4
//   / \
//  1   2
// Return false.

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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == nullptr)    return false;
        return equal(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    bool equal(TreeNode* t1, TreeNode* t2)
    {
        if(t1 == nullptr && t2 == nullptr)  return true;
        if(t1 != nullptr && t2 != nullptr)  
            return t1->val == t2->val && equal(t1->left, t2->left) && equal(t1->right, t2->right);
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(5);
    TreeNode *n1 = new TreeNode(1);    
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n0 = new TreeNode(0);
    n3->left = n4;
    n3->right = n5;
    n4->left = n1;
    n4->right = n2;
    TreeNode* s4 = new TreeNode(4);    
    TreeNode* s1 = new TreeNode(1);    
    TreeNode* s2 = new TreeNode(2);
    s4->left = s1;
    s4->right= s2;
    CHECK_TRUE(sln.isSubtree(n3, s4));
    n2->left = n0;
    CHECK_FALSE(sln.isSubtree(n3, s4));
    delete n3;
    delete n4;
    delete n5;
    delete n1;
    delete n2;
    delete n0;
    delete s4;    
    delete s1;
    delete s2;
    TEST_REPORT();
}