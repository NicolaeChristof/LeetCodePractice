// https://leetcode.com/problems/first-bad-version
// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int result = -1;

        int low = 0;
        int high = n;
        int mid;
        bool isBad;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            isBad = isBadVersion(mid);
            if (isBad)
            {
                if (mid > 0 && !isBadVersion(mid - 1))
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
};