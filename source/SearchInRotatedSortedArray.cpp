// https://leetcode.com/problems/search-in-rotated-sorted-array
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
            if (nums[mid] == target) return mid;

            // Left half is sorted
            if (nums[low] <= nums[mid])
            {
                // Can only reliably search for target within a sorted section
                if (nums[low] <= target && target < nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            // Right half is sorted
            else if (nums[high] > nums[mid])
            {
                // Can only reliably search for target within a sorted section
                if (nums[mid] < target && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};