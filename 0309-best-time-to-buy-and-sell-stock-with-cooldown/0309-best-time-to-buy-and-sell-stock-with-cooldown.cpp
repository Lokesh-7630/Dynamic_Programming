class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        // DP states: 
        // buy[i]  - Max profit on day i ending with a buy/hold state
        // sell[i] - Max profit on day i ending with a sold state
        vector<int> buy(n, 0);
        vector<int> sell(n, 0);

        // Base cases for day 0 and day 1
        buy[0] = -prices[0];
        sell[0] = 0;

        buy[1] = max(-prices[0], -prices[1]);
        sell[1] = max(0, buy[0] + prices[1]);

        for (int i = 2; i < n; ++i) {
            // To buy today, we must have been in a cooldown state yesterday. 
            // So we take the profit from two days ago (sell[i-2]) minus today's price.
            buy[i] = max(buy[i-1], sell[i-2] - prices[i]);
            
            // To sell today, we must have held the stock yesterday (buy[i-1]).
            sell[i] = max(sell[i-1], buy[i-1] + prices[i]);
        }

        return sell[n - 1];
    }
};