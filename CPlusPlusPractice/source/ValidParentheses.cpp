// https://leetcode.com/problems/valid-parentheses
#include <string>
#include <stack>
#include <unordered_map>

class Solution
{
    std::unordered_map<char, char> bracketMap = { { ')', '(' }, { '}', '{' }, { ']', '[' } };
public:
    bool isValid(std::string s)
    {
        if (s.empty()) return true;

        std::stack<char> stack;
        for (const char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                stack.push(c);
            }
            else
            {
                if (!stack.empty() && stack.top() == bracketMap[c])
                {
                    stack.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return stack.empty();
    }
};