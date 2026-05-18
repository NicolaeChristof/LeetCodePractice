// https://leetcode.com/problems/valid-anagram
#include <string>
#include <unordered_map>

class Solution
{
public:
    bool isAnagram(std::string s, std::string t)
    {
        if (s.size() != t.size()) return false;

        std::unordered_map<char, int> letters;

        for (const char& c : s) ++letters[c];
        for (const char& c : t) --letters[c];

        for (const auto& [key, value] : letters)
        {
            if (value != 0) return false;
        }

        return true;
    }
};