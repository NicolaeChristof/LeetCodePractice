// https://leetcode.com/problems/k-closest-points-to-origin
#include <vector>
#include <queue>

class Solution
{
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k)
    {
        std::priority_queue<std::vector<int>> maxHeap;
        std::vector<std::vector<int>> result;
        result.reserve(k);

        for (const std::vector<int>& point : points)
        {
            int x = point[0];
            int y = point[1];
            maxHeap.push({ x*x + y*y, x, y});
            if (maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }

        while (!maxHeap.empty())
        {
            result.push_back({ maxHeap.top()[1], maxHeap.top()[2] });
            maxHeap.pop();
        }

        return result;
    }
};