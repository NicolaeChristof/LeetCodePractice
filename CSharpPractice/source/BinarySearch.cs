// https://leetcode.com/problems/binary-search

namespace LeetCodePractice.BinarySearch
{
    public class Solution
    {
        public int Search(int[] nums, int target)
        {
            int low = 0;
            int high = nums.Length - 1;
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
    }
}