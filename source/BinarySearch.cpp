// https://leetcode.com/problems/binary-search
#include <vector>

class Solution
{
public:
    int search(std::vector<int>& nums, int target)
    {
        if (nums.empty()) return -1;

        int low = 0;
        int high = nums.size() - 1;
        int mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (target < nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return -1;
    }
};