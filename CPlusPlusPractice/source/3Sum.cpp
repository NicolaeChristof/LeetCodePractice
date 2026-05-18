// https://leetcode.com/problems/3sum
#include <vector>
#include <algorithm>
#include <unordered_map>

// Two pointer solution
class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        if (nums.size() < 3) return {};
        std::sort(nums.begin(), nums.end());
        if (nums[0] > 0) return {}; // all positive, no way to add to = 0

        std::vector<std::vector<int>> result;
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0)
                {
                    ++left;
                }
                else if (sum > 0)
                {
                    --right;
                }
                else
                {
                    result.push_back({ nums[i], nums[left], nums[right] });
                    ++left;
                    while (left < right && nums[left] == nums[left - 1]) ++left;
                }
            }
        }
        return result;
    }
};

// Hashmap solution
//class Solution
//{
//public:
//    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
//    {
//        if (nums.size() < 3) return {};
//        std::sort(nums.begin(), nums.end());
//        if (nums[0] > 0) return {}; // all positive, no way to add to = 0
//
//        std::unordered_map<int, int> numMap; // value, index
//        for (int i = 0; i < nums.size(); ++i) numMap[nums[i]] = i;
//
//        std::vector<std::vector<int>> result;
//
//        int complement = 0;
//        for (int i = 0; i < nums.size() - 2; ++i)
//        {
//            if (nums[i] > 0) break; // all positive, cant add to = 0
//            for (int j = i + 1; j < nums.size() - 1; ++j)
//            {
//                complement = -(nums[i] + nums[j]);
//                if (numMap.contains(complement) && numMap[complement] > j)
//                {
//                    result.push_back({ nums[i], nums[j], complement });
//                }
//                j = numMap[nums[j]]; // move j to the last occurence of nums[j] to avoid duplicates
//            }
//            i = numMap[nums[i]]; // move i to the last occurence of nums[i] to avoid duplicates
//        }
//        return result;
//    }
//};