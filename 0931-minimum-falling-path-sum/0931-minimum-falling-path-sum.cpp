class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }
        
        // Build the DP table row by row
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // 1. Directly above
                int up = matrix[i][j] + dp[i-1][j];
                
                // 2. Diagonally left-up (check boundary)
                int leftup = matrix[i][j];
                if (j > 0) {
                    leftup += dp[i-1][j-1];
                } else {
                    leftup += 1e9; // Invalid path
                }
                
                // 3. Diagonally right-up (check boundary)
                int rightup = matrix[i][j];
                if (j < m - 1) {
                    rightup += dp[i-1][j+1];
                } else {
                    rightup += 1e9; // Invalid path
                }
                
                // Take the minimum of the three valid incoming paths
                dp[i][j] = min(up, min(leftup, rightup));
            }
        }
        
        // Find the minimum value in the last row
        int mini = 1e9;
        for (int j = 0; j < m; j++) {
            mini = min(mini, dp[n-1][j]);
        }
        
        return mini;
    }
};