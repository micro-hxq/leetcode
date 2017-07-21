// 637. Average of Levels in Binary Tree

// Given a non-empty binary tree, return the average value of the nodes on each 
// level in the form of an array.

// Example 1:
// Input:
//     3
//    / \
//   9  20
//     /  \
//    15   7
// Output: [3, 14.5, 11]
// Explanation:
// The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 
// is 11. Hence return [3, 14.5, 11].
// Note:
// The range of node's value is in the range of 32-bit signed integer.

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
    // vector<double> averageOfLevels(TreeNode* root) {
    //     vector<double> ans;
    //     if(root == nullptr) return ans;
    //     vector<pair<long, int>> aux;
    //     helper(aux, root, 0);
    //     for(const auto& val : aux)
    //         ans.push_back(1.0 * val.first / val.second);
    //     return ans;
    // }

    // void helper(vector<pair<long, int>> &aux, TreeNode *root, int level)
    // {
    //     if(root == nullptr) return;
    //     if(aux.size() <= level)
    //         aux.push_back(make_pair(0, 0));
    //     ++aux[level].second;
    //     aux[level].first += root->val;
    //     helper(aux, root->left, level + 1);
    //     helper(aux, root->right, level + 1);
    // }


    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root == nullptr) return ans;
        vector<TreeNode*> que, aux;
        que.push_back(root);
        while(!que.empty())
        {
            int num = que.size();
            long sum = 0;
            for(auto cur : que)
            {
                sum += cur->val;
                if(cur->left) aux.push_back(cur->left);
                if(cur->right) aux.push_back(cur->right);
            }
            ans.push_back(1.0 * sum / num);
            que.clear();
            que.swap(aux);
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
    vector<double> ans = {3.0, 14.5, 11.0f};
    auto res = sln.averageOfLevels(n1);
    for(auto it1 = ans.begin(), it2 = res.begin(); it1 != ans.end(); ++it1, ++it2)
        CHECK_TRUE(abs(*it1 - *it2) < 1.0e-8);

    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;    

    TEST_REPORT();
}