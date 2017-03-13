// 515. Find Largest Value in Each Tree Row
// You need to find the largest value in each row of a binary tree.

// Example:
// Input: 

//           1
//          / \
//         3   2
//        / \   \  
//       5   3   9 

// Output: [1, 3, 9]

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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        helper(res, root, 0);
        return res;
    }

    void helper(vector<int>& res, TreeNode* node, int h)
    {
        if(node == nullptr) return;
        if(res.size() > h)
            res[h] = max(node->val, res[h]);
        else
            res.push_back(node->val);
        helper(res, node->left, h + 1);
        helper(res, node->right, h + 1);
    }
};

int main(int argc, char const *argv[])
{
    Solution sln;
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);    
    TreeNode *n31 = new TreeNode(3);    
    TreeNode *n32 = new TreeNode(3);
    TreeNode *n5 = new TreeNode(5);
    TreeNode *n9 = new TreeNode(9);

    n1->left = n31;
    n1->right = n2;
    n31->left = n5;
    n31->right = n32;
    n2->right = n9;

    vector<int> ans = {1, 3, 9};
    auto res = sln.largestValues(n1);

    CHECK_TRUE(ans.size() == res.size());
    CHECK_TRUE(ans == res);

    delete n1;
    delete n2;
    delete n31;
    delete n32;
    delete n5;
    delete n9;    
    TEST_REPORT();
}