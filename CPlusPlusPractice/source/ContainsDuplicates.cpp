// https://leetcode.com/problems/contains-duplicate
#include <vector>
#include <unordered_set>

class Solution
{
public:
    bool containsDuplicate(std::vector<int>& nums)
    {
        std::unordered_set<int> numSet;
        for (const int num : nums)
        {
            if (numSet.contains(num)) return true;
            numSet.insert(num);
        }
        return false;
    }
};