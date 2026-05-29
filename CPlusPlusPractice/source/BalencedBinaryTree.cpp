// https://leetcode.com/problems/balanced-binary-tree
#include <algorithm>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int CheckHeight(TreeNode* root)
    {
        if (root == nullptr) return 1;

        int leftHeight = CheckHeight(root->left);
        if (leftHeight == -1) return -1;

        int rightHeight = CheckHeight(root->right);
        if (rightHeight == -1) return -1;

        if (std::abs(leftHeight - rightHeight) > 1) return -1;

        return std::max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root)
    {
        if (root == nullptr) return true;

        return CheckHeight(root) != -1;
    }
};