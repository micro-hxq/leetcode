// 257. Binary Tree Paths
// Given a binary tree, return all root-to-leaf paths.

// For example, given the following binary tree:

//    1
//  /   \
// 2     3
//  \
//   5
// All root-to-leaf paths are:

// ["1->2->5", "1->3"]

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root)
        {
            string str = to_string(root->val);
            if(root->left == nullptr && root->right == nullptr)
                res.push_back(str);
            if(root->left)  traverse(res, str, root->left);
            if(root->right) traverse(res, str, root->right);
        }
        return res;
    }

    void traverse(vector<string>& res, const string& str, TreeNode* n)
    {
        string s = "->" + to_string(n->val);
        if(n->left == nullptr && n->right == nullptr)
            res.push_back(str + s);
        if(n->left)
            traverse(res, str + s, n->left);
        if(n->right)
            traverse(res, str + s, n->right);

    }
};


int main(int argc, char const *argv[])
{
    Solution sln;
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n5 = new TreeNode(5);

    n1->left = n2;
    n1->right = n3;
    n2->right = n5;

    vector<string> ans  = {"1->2->5", "1->3"};
    auto res = sln.binaryTreePaths(n1);

    sort(ans.begin(), ans.end());
    sort(res.begin(), res.end());

    CHECK_TRUE(ans.size() == res.size());
    CHECK_TRUE(ans == res);

    delete n1;
    delete n2;
    delete n3;
    delete n5;

    TEST_REPORT();
}