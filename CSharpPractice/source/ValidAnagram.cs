// https://leetcode.com/problems/valid-anagram
using System.Collections.Generic;

namespace LeetCodePractice.ValidAnagram
{
    public class Solution
    {
        public bool IsAnagram(string s, string t)
        {
            if (s.Length != t.Length) return false;

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
                
            foreach (char c in t)
            {
                if (letters.ContainsKey(c))
                {
                    --letters[c];
                }
                else
                {
                    return false; // character didnt appear in first string
                }
            }

            foreach (int value in letters.Values)
            {
                if (value != 0) return false;
            }

            return true;
        }
    }
}