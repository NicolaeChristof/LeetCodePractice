// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr || root == p || root == q) return root;

        // left and right will either be p or q or nullptr
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // if p and q are both found then this is the LCA
        if (left && right) return root;

        return left ? left : right;
    }
};