#include <string>

class Solution
{
public:
    bool isPalindrome(std::string s)
    {
        if (s.empty() || s.size() == 1) return true;

        std::string::iterator front = s.begin();
        std::string::iterator back = s.end();

        while (front < back)
        {
            while (front != s.end() && !std::isalnum(*front)) ++front;
            while (back != s.begin() && !std::isalnum(*back)) --back;

            if (front < back && std::tolower(*front) != std::tolower(*back))
            {
                return false;
            }

            ++front;
            --back;
        }

        return true;
    }
};