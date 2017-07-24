// 113. Path Sum II

// Given a binary tree and a sum, find all root-to-leaf paths where each 
// path's sum equals the given sum.

// For example:
// Given the below binary tree and sum = 22,
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
// return
// [
//    [5,4,11,2],
//    [5,8,4,5]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        vector<int> aux;
        helper(ans, aux, root, sum);
        return ans;
    }

    void helper(vector<vector<int>> &ans, vector<int> &aux, TreeNode *root, int sum)
    {
        if(root == nullptr) return;
        sum -= root->val;
        aux.push_back(root->val);
        if(root->left != nullptr)
            helper(ans, aux, root->left, sum);
        if(root->right != nullptr)
            helper(ans, aux, root->right, sum);
        if(sum == 0 && root->left == nullptr && root->right == nullptr)
            ans.push_back(aux);
        aux.pop_back();
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    
    TreeNode* n1 = new TreeNode(5);    
    TreeNode* n2 = new TreeNode(4);    
    TreeNode* n3 = new TreeNode(8);
    TreeNode* n4 = new TreeNode(11);
    TreeNode* n5 = new TreeNode(13);
    TreeNode* n6 = new TreeNode(4);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n8 = new TreeNode(2);
    TreeNode* n9 = new TreeNode(5);
    TreeNode* n10 = new TreeNode(1);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n3->left = n5;
    n3->right = n6;
    n4->left = n7;
    n4->right = n8;
    n6->left = n9;
    n6->right = n10;

    vector<vector<int>> ans = {
        {5, 4, 11, 2},
        {5, 8, 4, 5}
    };
    auto res = sln.pathSum(n1, 22);
    sort(ans.begin(), ans.end());
    sort(res.begin(), res.end());

    CHECK_TRUE(ans == res);

    delete n1;    
    delete n2;    
    delete n3;
    delete n4;
    delete n5;
    delete n6;
    delete n7;
    delete n8;
    delete n9;
    delete n10;

    TEST_REPORT();
}