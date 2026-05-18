// https://leetcode.com/problems/evaluate-reverse-polish-notation
#include <vector>
#include <string>
#include <stack>
#include <unordered_set>

class Solution
{
public:
    int evalRPN(std::vector<std::string>& tokens)
    {
        if (tokens.empty()) return 0;

        std::stack<int> numbers;
        std::unordered_set<std::string> operands = { "+", "-", "*", "/" };

        for (const std::string& str : tokens)
        {
            if (!operands.contains(str))
            {
                numbers.emplace(std::stoi(str));
            }
            else
            {
                int second = numbers.top();
                numbers.pop();
                int first = numbers.top();
                numbers.pop();
                if (str == "+")
                {
                    numbers.emplace(first + second);
                }
                else if (str == "-")
                {
                    numbers.emplace(first - second);
                }
                else if (str == "*")
                {
                    numbers.emplace(first * second);
                }
                else if (str == "/")
                {
                    numbers.emplace(first / second);
                }
            }
        }
        return numbers.top();
    }
};