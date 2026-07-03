#include <vector>
#include <string>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int m = s.length();
        int n = p.length();
        
        // dp[i][j] stores if s[0...i-1] matches p[0...j-1]
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
        
        // Base case: both empty
        dp[0][0] = true;
        
        // Base case: empty string s, non-empty pattern p
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }
        
        // Fill the 2D matrix
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    // Characters match, look at the remaining prefix
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    // '*' acts as empty sequence (dp[i][j-1]) 
                    // OR '*' consumes one character of s (dp[i-1][j])
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else {
                    // Mismatch
                    dp[i][j] = false;
                }
            }
        }
        
        return dp[m][n];
    }
};
