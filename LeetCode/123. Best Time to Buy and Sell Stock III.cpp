/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 *
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 *
 */

/**
 * Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
 * Description: DP, decompose into two statge, and reserve the  result cal before
 * Author: guozheng
 * Data: 20170901
 * */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0 )
            return 0;
        int profit = 0;
        int last = 0;
        int len = prices.size();
        vector<int> first(len);
        vector<int> second(len);
        int buy = prices[0];
        for(int i = 1; i < len; i++) {
            first[i] = max(first[i-1], prices[i] - buy);
            buy = min(buy, prices[i]);
        }
        int sell = prices[len-1];
        for(int i = len-2; i >= 0; i--) {
            second[i] = max(second[i+1], sell - prices[i]);
            sell =  max(sell, prices[i]);
        }
        for(int i = 0; i < len; i++) {
            profit = max(profit, first[i] + second[i]);
        }
        return profit;
    }
};

int main() {
    vector<int> prices;
    prices.push_back(2);
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(0);
    prices.push_back(1);
    Solution s;
    cout<<s.maxProfit(prices)<<endl;
}
