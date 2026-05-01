// https://leetcode.com/problems/validate-binary-search-tree
#include <limits>

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
    bool isValidBST(TreeNode* root)
    {
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
private:
    // need to use long long min and max to account for cases where root->val is equal to INT_MIN or INT_MAX
    bool isValid(TreeNode* root, const long long min, const long long max)
    {
        if (root == nullptr) return true;

        if (root->val <= min || root->val >= max) return false;

        return isValid(root->left, min, root->val) && isValid(root->right, root->val, max);
    }
};