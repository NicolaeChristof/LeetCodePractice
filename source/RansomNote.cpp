// https://leetcode.com/problems/ransom-note
#include <string>

#include <unordered_map>

class Solution
{
public:
    bool canConstruct(std::string ransomNote, std::string magazine)
    {
        std::unordered_map<char, int> letters;
        for (const char& c : magazine) ++letters[c];
        for (const char& c : ransomNote)
        {
            --letters[c];
            if (letters[c] < 0) return false;
        }
        return true;
    }
};