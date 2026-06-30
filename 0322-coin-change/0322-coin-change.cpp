class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // dp table of size n x (amount + 1)
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        
        // 1. Fix: Removed 'return' statements so the loop actually finishes initializing the first row
        for(int T = 0; T <= amount; T++){
            if(T % coins[0] == 0) {
                dp[0][T] = T / coins[0]; // Fix: Changed dp[n] to dp[0]
            } else {
                dp[0][T] = 1e9;          // Fix: Changed dp[n] to dp[0]
            }
        }
        
        // Populate the rest of the DP table
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= amount; j++){
                // Fix: Initialize to 1e9 instead of INT_MAX to prevent overflow when adding 1
                int ans1 = 1e9; 
                if(coins[i] <= j){
                    ans1 = 1 + dp[i][j - coins[i]];
                }
                
                int ans2 = 0 + dp[i - 1][j];
            
                // Fix: Store the result in the current table cell dp[i][j] instead of dp[n][amount]
                dp[i][j] = min(ans1, ans2);
            }
        }
        
        int ans = dp[n - 1][amount];
        if(ans >= 1e9) return -1;
        return ans;
    }
};