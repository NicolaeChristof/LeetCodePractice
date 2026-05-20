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
        for (const int price : prices)
        {
            if (price < lowestPrice)
            {
                lowestPrice = price;
                continue;
            }

            if (price - lowestPrice > maxProfit)
            {
                maxProfit = price - lowestPrice;
            }
        }

        return maxProfit;
    }
};