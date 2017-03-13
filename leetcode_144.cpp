// 144. Binary Tree Preorder Traversal
// Given a binary tree, return the preorder traversal of its nodes' values.

// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [1,2,3].

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        helper(res, st, root);
        while(!st.empty())
        {
            auto p = st.top();
            st.pop();
            if(p->right)
                helper(res, st, p->right);
        }
        return res;
    }
    void helper(vector<int>& res, stack<TreeNode*>& st, TreeNode* root)
    {
        while(root)
        {
            res.push_back(root->val);
            st.push(root);
            root = root->left;
        }
    }
};


int main(int argc, char const *argv[])
{
    Solution sln;
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);    
    
    n1->right = n2;
    n2->left = n3;

    vector<int> ans = {1, 2, 3};
    auto res = sln.preorderTraversal(n1);

    CHECK_TRUE(ans.size() == res.size());
    CHECK_TRUE(ans == res);

    delete n1;
    delete n2;
    delete n3;    
    TEST_REPORT();
}