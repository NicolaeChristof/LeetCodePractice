// https://leetcode.com/problems/valid-palindrome

namespace LeetCodePractice.ValidPalindrome
{
    public class Solution
    {
        public bool IsPalindrome(string s)
        {
            if (s.Length == 0 || s.Length == 1) return true;

            int front = 0;
            int back = s.Length - 1;

            while (front < back)
            {
                while (front < s.Length && !char.IsLetterOrDigit(s[front])) ++front;
                while (back >= 0 && !char.IsLetterOrDigit(s[back])) --back;

                if (front < back && char.ToLower(s[front]) != char.ToLower(s[back]))
                {
                    return false;
                }

                ++front;
                --back;
            }

            return true;
        }
    }
}