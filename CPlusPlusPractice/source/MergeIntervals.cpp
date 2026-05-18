// https://leetcode.com/problems/merge-intervals
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals)
    {
        std::sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> result;

        for (const std::vector<int>& interval : intervals)
        {
            // No overlap
            if (result.empty() || result.back()[1] < interval[0])
            {
                result.emplace_back(interval);
            }
            // Overlap, update the upper bounds of the last element in result vector
            else
            {
                result.back()[1] = std::max(result.back()[1], interval[1]);
            }
        }

        return result;
    }
};