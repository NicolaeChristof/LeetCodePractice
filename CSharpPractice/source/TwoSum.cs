// https://leetcode.com/problems/two-sum
using System.Collections.Generic;

public class Solution
{
    public int[] TwoSum(int[] nums, int target)
    {
        Dictionary<int, int> complementMap = new Dictionary<int, int>(nums.Length); // value, index
        int complement = 0;
        for (int i = 0; i < nums.Length; ++i)
        {
            complement = target - nums[i];
            if (complementMap.TryGetValue(complement, out int index))
            {
                return new int[] { index, i };
            }
            complementMap[nums[i]] = i;
        }
        return Array.Empty<int>();
    }
}