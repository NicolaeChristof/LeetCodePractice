// https://leetcode.com/problems/insert-interval
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval)
    {
        std::vector<std::vector<int>> result;

        for (const std::vector<int>& interval : intervals)
        {
            // new interval comes before current interval
            if (newInterval[1] < interval[0])
            {
                result.emplace_back(newInterval);
                newInterval = interval;
            }
            // new interval comes after current interval
            else if (interval[1] < newInterval[0])
            {
                result.emplace_back(interval);
            }
            // current interval overlaps with new interval
            else
            {
                newInterval[0] = std::min(newInterval[0], interval[0]);
                newInterval[1] = std::max(newInterval[1], interval[1]);
            }
        }
        result.emplace_back(newInterval);

        return result;
    }
};