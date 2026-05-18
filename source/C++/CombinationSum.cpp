// https://leetcode.com/problems/combination-sum
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target)
    {
        std::vector<std::vector<int>> result;
        std::vector<int> current;

        Backtrack(candidates, target, 0, current, result);

        return result;
    }
private:
    void Backtrack(std::vector<int>& candidates, int target, int index, std::vector<int>& current, std::vector<std::vector<int>>& result)
    {
        if (target == 0)
        {
            result.emplace_back(current);
            return;
        }

        // Overshot target or ran out of candidates to try
        if (target < 0 || index >= candidates.size()) return;

        // Try adding current candidate again
        current.emplace_back(candidates[index]);
        Backtrack(candidates, target - candidates[index], index, current, result);

        // remove the last candidate and try the next candidate
        current.pop_back();
        Backtrack(candidates, target, index + 1, current, result);
    }
};