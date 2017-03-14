// 108. Convert Sorted Array to Binary Search Tree
// Given an array where elements are sorted in ascending order, convert it to a 
// height balanced BST.

#include "leetcode.hpp"


// Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    using VIter = typename vector<int>::iterator;
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums.begin(), nums.end());
    }

    TreeNode* helper(VIter first, VIter last)
    {
        if(first == last)   return nullptr;
        auto mid = first + (last - first) / 2;
        TreeNode *node = new TreeNode(*mid);
        node->left = helper(first, mid);
        node->right = helper(mid + 1, last);
        return node;
    }
};

class TreeValidation {
public:
    static bool validate(TreeNode* root)
    {
        if(root == nullptr) return true;
        return abs(height(root->left) - height(root->right)) < 2 && sorted(root);
    }

    static int height(TreeNode* root)
    {
        if(root == nullptr) return 0;
        int hl = height(root->left);
        int hr = height(root->right);
        return max(hl, hr) + 1;
    }

    static bool sorted(TreeNode* root)
    {
        if(root == nullptr)     return true;
        bool flag = true;
        if(root->left)
            flag = root->left->val < root->val;
        if(root->right)
            flag = flag && (root->val < root->right->val);
        flag = flag && sorted(root->left);
        flag = flag && sorted(root->right);
        return flag;
    }
};


int main(int argc, char const *argv[])
{
    Solution sln;
    vector<int> nums;
    for(int i = 0; i < 100; ++i)
    {
        CHECK_TRUE(TreeValidation::validate(sln.sortedArrayToBST(nums)));
        nums.push_back(i);
    }
    TEST_REPORT();
}