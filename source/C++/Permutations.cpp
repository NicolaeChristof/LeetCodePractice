// https://leetcode.com/problems/permutations
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        std::vector<bool> visited(nums.size(), false);

        Backtrack(nums, current, result, visited);

        return result;
    }
private:
    void Backtrack(std::vector<int>& nums, std::vector<int>& current, std::vector<std::vector<int>>& result, std::vector<bool>& visited)
    {
        if (current.size() == nums.size())
        {
            result.emplace_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (visited[i]) continue;
            visited[i] = true;

            current.emplace_back(nums[i]);
            Backtrack(nums, current, result, visited);
            current.pop_back();

            visited[i] = false;
        }
    }
};