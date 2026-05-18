// https://leetcode.com/problems/two-sum
#include <vector>
#include <unordered_map>

// One pass hashMap solution
class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> hashMap; // value, index
        int complement = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            complement = target - nums[i];
            if (hashMap.contains(complement))
            {
                return std::vector<int>({ i, hashMap[complement] });
            }
            hashMap[nums[i]] = i;
        }
        return std::vector<int>();
    }
};

//// Two pass hashmap solution
//class Solution
//{
//public:
//    std::vector<int> twoSum(std::vector<int>& nums, int target)
//    {
//        std::unordered_map<int, int> hashMap; // value, index
//        for (int i = 0; i < nums.size(); ++i)
//        {
//            hashMap[nums[i]] = i;
//        }
//
//        int complement = 0;
//        for (int i = 0; i < nums.size(); ++i)
//        {
//            complement = target - nums[i];
//            if (hashMap.contains(complement) && hashMap[complement] != i)
//            {
//                return std::vector<int>({ i, hashMap[complement] });
//            }
//        }
//        return std::vector<int>();
//    }
//};