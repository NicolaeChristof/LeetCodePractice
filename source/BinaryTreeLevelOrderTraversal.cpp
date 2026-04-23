// https://leetcode.com/problems/binary-tree-level-order-traversal
#include <vector>
#include <queue>

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
    std::vector<std::vector<int>> levelOrder(TreeNode* root)
    {
        if (root == nullptr) return {};

        std::vector<std::vector<int>> result;
        std::queue<TreeNode*> q;

        q.emplace(root);

        while (!q.empty())
        {
            int qSize = q.size();
            std::vector<int> layer;
            for (int i = 0; i < qSize; ++i)
            {
                TreeNode* node = q.front();
                q.pop();

                layer.emplace_back(node->val);

                if (node->left != nullptr) q.emplace(node->left);
                if (node->right != nullptr) q.emplace(node->right);
            }
            result.emplace_back(layer);
        }
        return result;
    }
};