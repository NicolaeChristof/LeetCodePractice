// https://leetcode.com/problems/sort-colors
#include <vector>

class Solution
{
public:
    void sortColors(std::vector<int>& nums)
    {
        int numRed = 0;
        int numWhite = 0;

        // count each color (dont need to count final color since using else statment below for final color)
        for (const int num : nums)
        {
            switch (num)
            {
                case 0: ++numRed; break;
                case 1: ++numWhite; break;
            }
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (i < numRed) nums[i] = 0;
            else if (i < numRed + numWhite) nums[i] = 1;
            else nums[i] = 2;
        }
    }
};