// https://leetcode.com/problems/first-bad-version

namespace LeetCodePractice.FirstBadVersion
{
    // The isBadVersion API is defined in the parent class VersionControl.
    // bool IsBadVersion(int version);

    public class Solution : VersionControl
    {
        public int FirstBadVersion(int n)
        {
            int result = -1;

            int low = 0;
            int high = n;
            int mid;
            bool isBad;
            while (low <= high)
            {
                mid = low + (high - low) / 2;
                isBad = IsBadVersion(mid);
                if (isBad)
                {
                    if (mid > 0 && !IsBadVersion(mid - 1))
                    {
                        result = mid;
                        break;
                    }
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            return result;
        }
    }
}