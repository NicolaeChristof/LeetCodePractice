// https://leetcode.com/problems/ransom-note
using System.Collections.Generic;

namespace LeetCodePractice.RansomNote
{
    public class Solution
    {
        public bool CanConstruct(string ransomNote, string magazine)
        {
            Dictionary<char, int> letters = new Dictionary<char, int>();
            foreach (char c in magazine)
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
            foreach (char c in ransomNote)
            {
                if (letters.ContainsKey(c))
                {
                    --letters[c];
                    if (letters[c] < 0) return false;
                }
                else
                {
                    return false; // character didnt appear in first string
                }
            }
            return true;
        }
    }
}