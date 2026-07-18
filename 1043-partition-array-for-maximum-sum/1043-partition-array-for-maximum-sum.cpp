class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        // dp[i] stores the maximum sum for the first i elements
        std::vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            int current_max = 0;
            // Try all possible lengths for the last partition (up to k)
            for (int j = 1; j <= k && i - j >= 0; ++j) {
                // Keep track of the maximum element in the current partition arr[i-j ... i-1]
                current_max = std::max(current_max, arr[i - j]);
                
                // dp[i] is the max of its current value or the optimal split before this partition + value of this partition
                dp[i] = std::max(dp[i], dp[i - j] + current_max * j);
            }
        }

        return dp[n];
    }
};