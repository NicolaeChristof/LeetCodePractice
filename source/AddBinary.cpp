// https://leetcode.com/problems/add-binary
#include <string>

class Solution
{
public:
    std::string addBinary(std::string a, std::string b)
    {
        int iter1 = a.size() - 1;
        int iter2 = b.size() - 1;
        std::string result;
        int carry = 0;

        while (iter1 >= 0 || iter2 >= 0 || carry > 0)
        {
            if (iter1 >= 0) carry += a[iter1] - '0'; // subtracting '0' converts from character to int
            if (iter2 >= 0) carry += b[iter2] - '0';

            result.insert(0, std::to_string(carry % 2));
            carry /= 2;

            --iter1;
            --iter2;
        }

        return result;
    }
};

// Iterative solution
//class Solution
//{
//public:
//    std::string addBinary(std::string a, std::string b)
//    {
//        std::string::reverse_iterator iter1 = a.rbegin();
//        std::string::reverse_iterator iter2 = b.rbegin();
//        std::string result;
//        bool carry = false;
//
//        while (iter1 != a.rend() && iter2 != b.rend())
//        {
//            if (*iter1 == '0' && *iter2 == '0')
//            {
//                carry ? result.insert(0, "1") : result.insert(0, "0");
//                carry = false;
//            }
//            else if (*iter1 != *iter2)
//            {
//                if (carry)
//                {
//                    result.insert(0, "0");
//                    // carry stays true
//                }
//                else
//                {
//                    result.insert(0, "1");
//                    carry = false;
//                }
//            }
//            else if (*iter1 == '1' && *iter2 == '1')
//            {
//                if (carry)
//                {
//                    result.insert(0, "1");
//                    // carry stays true
//                }
//                else
//                {
//                    result.insert(0, "0");
//                    carry = true;
//                }
//            }
//
//            ++iter1;
//            ++iter2;
//        }
//        while (iter1 != a.rend())
//        {
//            if (*iter1 == '0')
//            {
//                if (carry)
//                {
//                    result.insert(0, "1");
//                    carry = false;
//                }
//                else
//                {
//                    result.insert(0, "0");
//                }
//            }
//            else
//            {
//                if (carry)
//                {
//                    result.insert(0, "0");
//                    // carry stays true
//                }
//                else
//                {
//                    result.insert(0, "1");
//                }
//            }
//            ++iter1;
//        }
//        while (iter2 != b.rend())
//        {
//            if (*iter2 == '0')
//            {
//                if (carry)
//                {
//                    result.insert(0, "1");
//                    carry = false;
//                }
//                else
//                {
//                    result.insert(0, "0");
//                }
//            }
//            else
//            {
//                if (carry)
//                {
//                    result.insert(0, "0");
//                    // carry stays true
//                }
//                else
//                {
//                    result.insert(0, "1");
//                }
//            }
//            ++iter2;
//        }
//        if (carry) result.insert(0, "1");
//
//        return result;
//    }
//};