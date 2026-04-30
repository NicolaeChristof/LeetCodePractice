// https://leetcode.com/problems/coin-change
#include <vector>
#include <algorithm>

// Dynamic Programming (bottom up): Tabulation solution
class Solution
{
public:
    int coinChange(std::vector<int>& coins, int amount)
    {
        // The default value just needs to be something bigger than amount.
        std::vector<int> memoization(amount + 1, amount + 1); // index: amount, value: minCoins.
        memoization[0] = 0;

        for (int currAmount = 1; currAmount < amount + 1; ++currAmount)
        {
            for (const int coin : coins)
            {
                if (currAmount - coin >= 0)
                {
                    memoization[currAmount] = std::min(memoization[currAmount], memoization[currAmount - coin] + 1);
                }
            }
        }

        return memoization[amount] == amount + 1 ? -1 : memoization[amount];
    }
};

// Dynamic Programming (top down): Memoization solution (caching results)
// Notes: using a pre-allocated vector is significantly faster than using a map for memoization
//class Solution
//{
//public:
//    int coinChange(std::vector<int>& coins, int amount)
//    {
//        std::vector<int> memoization(amount + 1, INT_MAX); // index: amount, value: minCoins
//        return CalculateChange(coins, amount, memoization);
//    }
//private:
//    int CalculateChange(const std::vector<int>& coins, const int amount, std::vector<int>& memoization)
//    {
//        if (amount < 0) return -1;
//        if (amount == 0) return 0;
//        if (memoization[amount] != INT_MAX) return memoization[amount];
//
//        int minCoins = INT_MAX;
//
//        for (const int coin : coins)
//        {
//            const int result = CalculateChange(coins, amount - coin, memoization);
//            if (result >= 0 && result < minCoins) minCoins = result + 1;
//        }
//
//        memoization[amount] = (minCoins == INT_MAX) ? -1 : minCoins;
//        return memoization[amount];
//    }
//};

// Recursive solution
//class Solution
//{
//public:
//    int coinChange(std::vector<int>& coins, int amount)
//    {
//        if (amount < 0) return -1;
//        if (amount == 0) return 0;
//
//        int minCoins = INT_MAX;
//
//        for (const int coin : coins)
//        {
//            const int result = coinChange(coins, amount - coin);
//            if (result >= 0 && result < minCoins) minCoins = result + 1;
//        }
//
//        return (minCoins == INT_MAX) ? -1 : minCoins;
//    }
//};