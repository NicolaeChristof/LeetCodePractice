// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

namespace LeetCodePractice.BestTimeToBuyAndSellStock
{
    public class Solution
    {
        public int MaxProfit(int[] prices)
        {
            if (prices.Length == 0) return 0;

            int lowestPrice = prices[0];
            int maxProfit = 0;
            foreach (int price in prices)
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
    }
}