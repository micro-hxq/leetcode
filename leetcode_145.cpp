// 145. Binary Tree Postorder Traversal

// Given a binary tree, return the postorder traversal of its nodes' values.

// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [3,2,1].

// Note: Recursive solution is trivial, could you do it iteratively?


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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        while(root || !st.empty())
        {
            if(root != nullptr)
            {
                st.push(root);
                ans.push_back(root->val);
                root = root->right;
            }
            else
            {
                root = st.top();
                st.pop();
                root = root->left;
            }
        }
        return vector<int>(ans.crbegin(), ans.crend());
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

    vector<int> ans = {3, 2, 1};
    CHECK_TRUE(ans == sln.postorderTraversal(n1));

    delete n1;
    delete n2;    
    delete n3;

    TEST_REPORT();
}