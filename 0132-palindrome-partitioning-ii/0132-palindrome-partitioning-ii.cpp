class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        if (n <= 1) return 0;

        // Step 1: Precompute palindrome table
        // isPal[i][j] will be true if s[i...j] is a palindrome
        std::vector<std::vector<bool>> isPal(n, std::vector<bool>(n, false));
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j]) {
                    // A substring s[i...j] is a palindrome if:
                    // 1. It is 1 or 2 characters long (j - i <= 2)
                    // 2. The inner substring s[i+1...j-1] is a palindrome
                    if (j - i <= 2 || isPal[i + 1][j - 1]) {
                        isPal[i][j] = true;
                    }
                }
            }
        }

        // Step 2: Calculate minimum cuts
        // dp[i] stores the min cuts needed for substring s[0...i]
        std::vector<int> dp(n, 0);
        
        for (int i = 0; i < n; ++i) {
            // Maximum cuts needed for s[0...i] is i cuts (cutting every character)
            int min_cuts = i; 
            
            for (int j = 0; j <= i; ++j) {
                if (isPal[j][i]) {
                    // If the entire prefix s[0...i] is a palindrome, 0 cuts are needed
                    if (j == 0) {
                        min_cuts = 0;
                    } else {
                        // Otherwise, it's the cuts needed for s[0...j-1] plus 1 cut
                        min_cuts = std::min(min_cuts, dp[j - 1] + 1);
                    }
                }
            }
            dp[i] = min_cuts;
        }

        return dp[n - 1];
    }
};