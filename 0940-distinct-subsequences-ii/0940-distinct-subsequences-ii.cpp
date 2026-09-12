class Solution {
public:
    
    int distinctSubseqII(string s) {
       const int MOD = 1e9 + 7;
        // last[i] stores the count of distinct subsequences ending in character ('a' + i)
        std::vector<long long> last(26, 0);

        for (char c : s) {
            int idx = c - 'a';
            
            // Sum all distinct subsequences built so far
            long long current_total = 0;
            for (int i = 0; i < 26; ++i) {
                current_total = (current_total + last[i]) % MOD;
            }
            
            // Add 1 for the new single-character subsequence consisting of `c` alone
            last[idx] = (current_total + 1) % MOD;
        }

        // Total count of distinct subsequences is the sum of choices ending in any letter
        long long result = 0;
        for (int i = 0; i < 26; ++i) {
            result = (result + last[i]) % MOD;
        }

        return result;

    }
};