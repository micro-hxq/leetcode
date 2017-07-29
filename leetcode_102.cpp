// 102. Binary Tree Level Order Traversal

// Given a binary tree, return the level order traversal of its 
// nodes' values. (ie, from left to right, level by level).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans; 
        if(root == nullptr) return ans;
        vector<TreeNode*> cur, next;
        cur.push_back(root);
        while(!cur.empty())
        {
            vector<int> level;
            for(auto node : cur)
            {
                level.push_back(node->val);
                if(node->left != nullptr)
                    next.push_back(node->left);
                if(node->right != nullptr)
                    next.push_back(node->right);
            }
            ans.push_back(std::move(level));
            cur.clear();
            cur.swap(next);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    
    TreeNode *n1 = new TreeNode(3);
    TreeNode *n2 = new TreeNode(9);
    TreeNode *n3 = new TreeNode(20);
    TreeNode *n4 = new TreeNode(15);
    TreeNode *n5 = new TreeNode(7);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    vector<vector<int>> ans = {{3}, {9, 20}, {15, 7}};
    CHECK_TRUE(sln.levelOrder(n1) == ans);

    delete n1;
    delete n2;    
    delete n3;    
    delete n4;
    delete n5;

    TEST_REPORT();
}