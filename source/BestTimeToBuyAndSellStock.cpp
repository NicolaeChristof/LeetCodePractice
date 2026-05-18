// https://leetcode.com/problems/best-time-to-buy-and-sell-stock
#include <vector>

class Solution
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        if (prices.empty()) return 0;

        int lowestPrice = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] < lowestPrice)
            {
                lowestPrice = prices[i];
                continue;
            }

            if (prices[i] - lowestPrice > maxProfit)
            {
                maxProfit = prices[i] - lowestPrice;
            }
        }

        return maxProfit;
    }
};