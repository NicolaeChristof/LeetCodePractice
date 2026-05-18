// https://leetcode.com/problems/majority-element
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int majorityElement(std::vector<int>& nums)
    {
        std::unordered_map<int, int> numCount;

        for (const int num : nums)
        {
            ++numCount[num];
            if (numCount[num] > nums.size() / 2) return num;
        }
        return -1;
    }
};