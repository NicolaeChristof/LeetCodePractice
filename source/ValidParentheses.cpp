#include <string>

#include <stack>
#include <unordered_map>

class Solution
{
public:
    bool isValid(std::string s)
    {
        std::stack<char> stack;
        std::unordered_map<char, char> hashMap = { { ')', '(' }, { '}', '{' }, { ']', '[' } };

        for (const char& c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                stack.push(c);
            }
            else
            {
                if (!stack.empty() && stack.top() == hashMap[c])
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