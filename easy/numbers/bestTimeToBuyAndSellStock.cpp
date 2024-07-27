/**
 * 121. Best Time to Buy and Sell Stock
 * 
 * You are given an array 'p_prices' where 'p_prices'[i] is the price of a given stock on the ith day.
 * 
 * You want to maximize your profit by choosing a single day to buy one stock
 * and choosing a different day in the future to sell that stock.
 * 
 * Return the maximum profit you can achieve from this transaction.
 * If you cannot achieve any profit, return 0.
 * 
 */

#include <vector>
#include <map>
#include <iostream>

int maxProfit(const std::vector<int>& p_prices)
{
    int maximumProfit = 0;
    size_t buyIndex = 0;

    for (size_t sellIndex = 1; sellIndex < p_prices.size(); sellIndex++) {
        int cost = p_prices.at(buyIndex);
        int reward = p_prices.at(sellIndex);
        int profit = reward - cost;

        // reward was smaller than cost
        if (profit < 0) {
            buyIndex = sellIndex;
            continue;
        }

        // updates new maximum profit if necessary
        if (profit > maximumProfit) {
            maximumProfit = profit;
        }
    }

    return maximumProfit;
}

int main(void)
{
    std::vector<int> pricesOne = { 7, 1, 5, 3, 6, 4 };
    std::cout << maxProfit(pricesOne) << "\n";

    std::vector<int> pricesTwo = { 2, 1, 2, 0, 1 }; // 7, 6, 4, 3, 1
    std::cout << maxProfit(pricesTwo) << "\n";
}
