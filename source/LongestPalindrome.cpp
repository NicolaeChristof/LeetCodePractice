// https://leetcode.com/problems/longest-palindrome
#include <string>
#include <unordered_map>

class Solution
{
public:
    int longestPalindrome(std::string s)
    {
        if (s.empty()) return 0;
        if (s.size() == 1) return 1;

        std::unordered_map<char, int> letters;
        for (const char& c : s) ++letters[c];

        int total = 0;
        bool odd = false;
        for (const auto& [key, value] : letters)
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
};