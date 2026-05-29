// https://leetcode.com/problems/balanced-binary-tree
using System;

namespace LeetCodePractice.BalancedBinaryTree
{
    // Definition for a binary tree node.
    public class TreeNode
    {
        public int val;
        public TreeNode left;
        public TreeNode right;
        public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
        {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public class Solution
    {
        int CheckHeight(TreeNode root)
        {
            if (root == null) return 1;

            int leftHeight = CheckHeight(root.left);
            if (leftHeight == -1) return -1;

            int rightHeight = CheckHeight(root.right);
            if (rightHeight == -1) return -1;

            if (Math.Abs(leftHeight - rightHeight) > 1) return -1;

            return Math.Max(leftHeight, rightHeight) + 1;
        }

        public bool IsBalanced(TreeNode root)
        {
            if (root == null) return true;

            return CheckHeight(root) != -1;
        }
    }
}