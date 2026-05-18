// https://leetcode.com/problems/longest-substring-without-repeating-characters
#include <string>
#include <unordered_map>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        if (s.size() == 0) return 0;

        int result = -1;
        std::unordered_map<char, int> letters; // letter, index
        int slow = 0;

        for (int fast = 0; fast < s.size(); ++fast)
        {
            if (!letters.contains(s[fast]) || letters[s[fast]] < slow)
            {
                letters[s[fast]] = fast;
                result = std::max(result, fast - slow + 1);
            }
            else
            {
                slow = letters[s[fast]] + 1;
                letters[s[fast]] = fast;
            }
        }

        return result;
    }
};

// Set solution
// #include <unordered_set>
// 
//class Solution
//{
//public:
//    int lengthOfLongestSubstring(std::string s)
//    {
//        if (s.size() == 0) return 0;
//
//        int result = -1;
//        std::unordered_set<char> letters;
//        int slow = 0;
//
//        for (int fast = 0; fast < s.size(); ++fast)
//        {
//            if (!letters.contains(s[fast]))
//            {
//                letters.insert(s[fast]);
//                result = std::max(result, fast - slow + 1);
//            }
//            else
//            {
//                while (letters.contains(s[fast]))
//                {
//                    letters.erase(s[slow]);
//                    ++slow;
//                }
//                letters.insert(s[fast]);
//            }
//        }
//
//        return result;
//    }
//};