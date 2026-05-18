// https://leetcode.com/problems/maximum-depth-of-binary-tree
#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    int result = 0;
public:
    int DFS(TreeNode* root)
    {
        if (root == nullptr) return 1;

        int left = DFS(root->left);
        int right = DFS(root->right);

        result = std::max(result, std::max(left, right));

        return std::max(left, right) + 1;
    }

    int maxDepth(TreeNode* root)
    {
        DFS(root);
        return result;
    }
};