// https://leetcode.com/problems/maximum-subarray
#include <vector>
#include <algorithm>

// Kadane's Algorithm
class Solution
{
public:
    int maxSubArray(std::vector<int>& nums)
    {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];

        int largestSum = nums[0];
        int currMax = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            currMax = std::max(nums[i], currMax + nums[i]);
            largestSum = std::max(largestSum, currMax);
        }
        return largestSum;
    }
};