// https://leetcode.com/problems/longest-palindrome
using System.Collections.Generic;

namespace LeetCodePractice.LongestPalindrome
{
    public class Solution
    {
        public int LongestPalindrome(string s)
        {
            if (s.Length == 0) return 0;
            if (s.Length == 1) return 1;

            Dictionary<char, int> letters = new Dictionary<char, int>();
            foreach (char c in s)
            {
                if (letters.ContainsKey(c))
                {
                    ++letters[c];
                }
                else
                {
                    letters[c] = 1;
                }
            }

            int total = 0;
            bool odd = false;
            foreach (var (key, value) in letters)
            {
                if (value % 2 == 0) // Even
                {
                    total += value;
                }
                else // Odd
                {
                    total += (value - 1);
                    odd = true;
                }
            }
            if (odd) ++total;
            return total;
        }
    }
}