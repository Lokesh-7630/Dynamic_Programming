class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int sum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If it's the first row or first column, dp[i][j] is just matrix[i][j]
                if (i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j];
                } 
                // For other cells, if matrix[i][j] == 1, take 1 + min of top, left, top-left
                else if (matrix[i][j] == 1) {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
                }
                
                // Keep adding to the answer directly to avoid an extra double-loop
                sum += dp[i][j];
            }
        }

        return sum;
    }
};