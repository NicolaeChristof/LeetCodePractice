// https://leetcode.com/problems/valid-parentheses
using System.Collections.Generic;

namespace LeetCodePractice.ValidParentheses
{
    public class Solution
    {
        private Dictionary<char, char> bracketMap = new Dictionary<char, char> { { '}', '{' }, { ']', '[' }, { ')', '(' } };
        public bool IsValid(string s)
        {
            if (s.Length == 0) return true;

            Stack<char> stack = new Stack<char>();
            foreach (char c in s)
            {
                if (c == '{' || c == '[' || c == '(')
                {
                    stack.Push(c);
                }
                else
                {
                    if (stack.Count > 0 && stack.Peek() == bracketMap[c])
                    {
                        stack.Pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            return stack.Count == 0;
        }
    }
}