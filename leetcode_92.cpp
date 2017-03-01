// 94. Binary Tree Inorder Traversal
// Given a binary tree, return the inorder traversal of its nodes' values.
// For example:
// Given binary tree [1,null,2,3],
//    1
//     \
//      2
//     /
//    3
// return [1,3,2].

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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        push(root, st);
        while(!st.empty())
        {
            auto cur = st.top();
            st.pop();
            res.push_back(cur->val);
            push(cur->right, st);
        }
        return res;
    }

    void push(TreeNode* root, stack<TreeNode*>& st)
    {
        while(root)
        {
            st.push(root);
            root = root->left;
        }
    }
};


int main(int argc, char const *argv[])
{
    Solution sln;
    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(3);
    root->right = node1;
    node1->left = node2;

    vector<int> ans = {1, 3, 2};
    auto res = sln.inorderTraversal(root);
    CHECK_TRUE(ans == res);

    delete root;
    delete node1;
    delete node2;
    TEST_REPORT();
}