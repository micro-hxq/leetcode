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

// Note: Recursive solution is trivial, could you do it iteratively?


#include "leetcode.hpp"


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int> ans;
        // stack<TreeNode*> st;
        // while(root || !st.empty())
        // {
        //     while(root)
        //     {
        //         st.push(root);
        //         root = root->left;
        //     }
        //     root = st.top();
        //     st.pop();
        //     ans.push_back(root->val);
        //     root = root->right;
        // }
        // return ans;

        vector<int> ans;
        stack<TreeNode*> st;
        while(root || !st.empty())
        {
            if(root != nullptr)
            {
                st.push(root);
                root = root->left;
            }
            else
            {
                root = st.top();
                st.pop();
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution sln;

    TreeNode* n1 = new TreeNode(1);       
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    n1->right = n2;
    n2->left = n3;

    vector<int> ans = {1, 3, 2};
    CHECK_TRUE(ans == sln.inorderTraversal(n1));

    delete n1;
    delete n2;
    delete n3;    

    TEST_REPORT();
}