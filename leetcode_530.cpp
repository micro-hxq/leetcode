// 530. Minimum Absolute Difference in BST
// Given a binary search tree with non-negative values, find the minimum absolute
// difference between values of any two nodes.

// Example:
// Input:

//    1
//     \
//      3
//     /
//    2

// Output:
// 1

// Explanation:
// The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).

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
    int getMinimumDifference(TreeNode* root) {
        vector<int> nums;
        midOrder(root, nums);
        int res = INT_MAX;
        for(size_t i = 1; i < nums.size(); ++i)
            res = min(res, nums[i] - nums[i - 1]);
        return res;
    }

    void midOrder(TreeNode* root, vector<int>& nums)
    {
        if(root == nullptr) return;
        midOrder(root->left, nums);
        nums.push_back(root->val);
        midOrder(root->right, nums);
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(2);
    root->right = node1;
    node1->left = node2;
    CHECK_TRUE(sln.getMinimumDifference(root) == 1);
    TEST_REPORT();
}