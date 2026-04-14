// https://leetcode.com/problems/climbing-stairs
class Solution
{
public:
    int climbStairs(int n)
    {
        int curr = -1;
        int prev1 = 1;
        int prev2 = 0;
        for (int i = 0; i < n; ++i)
        {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};