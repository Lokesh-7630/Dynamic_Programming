class Solution {
public: 
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // Edge case: if start or end is blocked, 0 paths are possible
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        
        // Use long long for the table to safely sum paths without overflow
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[m-1][n-1] = 1;
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // Skip the destination cell
                if (i == m - 1 && j == n - 1) continue;
                
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    long long right = (j < n - 1) ? dp[i][j+1] : 0;
                    long long bottom = (i < m - 1) ? dp[i+1][j] : 0;
                    
                    // No modulo needed! Just add them up.
                    dp[i][j] = right + bottom;
                }
            }
        }
        
        // Cast back to int to match the function return type
        return (int)dp[0][0];
    }
};