/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */

/**
 * Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 * Description: easy question no trick
 * Author: guozheng
 * Data: 20170901
 * */

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        if( prices.size() == 0)
            return profit;
        int buy = prices[0];
        for(int i = 0; i < prices.size(); i++){
            int price = prices[i];
            int profit_cell = max(0, price - buy);
            if( profit_cell == 0 )
                buy = min(buy, price);
            else
                buy = price;
            profit = profit + profit_cell;
        }
        return profit;
    }
};
