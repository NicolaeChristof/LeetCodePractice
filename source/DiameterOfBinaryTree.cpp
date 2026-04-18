// https://leetcode.com/problems/diameter-of-binary-tree
#include <algorithm>

//Definition for a binary tree node.
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
    int result = -1;
public:
    int DFS(TreeNode* root)
    {
        if (root == nullptr) return 0;

        int left = DFS(root->left);
        int right = DFS(root->right);

        result = std::max(result, left + right);

        return std::max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
        DFS(root);
        return result;
    }
};