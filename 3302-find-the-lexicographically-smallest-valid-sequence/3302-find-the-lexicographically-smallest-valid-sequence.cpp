class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        // R[j] stores the maximum (rightmost) starting index in word1 
        // to perfectly match the suffix word2[j...m-1]
        vector<int> R(m, -1);
        int ptr = n - 1;
        for (int j = m - 1; j >= 0; --j) {
            // Find the rightmost match for word2[j]
            while (ptr >= 0 && word1[ptr] != word2[j]) {
                ptr--;
            }
            if (ptr >= 0) {
                R[j] = ptr;
                ptr--; // Move pointer left for the next character
            } else {
                break; // Missing characters, impossible to match rest
            }
        }
        
        vector<int> ans;
        int i = 0; // Pointer for word1
        bool changed = false; // Tracks if we used our single mismatch allowed
        
        for (int j = 0; j < m; ++j) {
            bool found = false;
            
            // Greedily find the earliest valid index for word2[j]
            while (i < n) {
                if (word1[i] == word2[j]) {
                    // Option 1: Exact match - optimally saves our mismatch
                    ans.push_back(i);
                    i++;
                    found = true;
                    break;
                } else if (!changed && (j + 1 == m || i < R[j+1])) {
                    // Option 2: Use mismatch - ensures lexicographically smallest index
                    // Check if remaining string can perfectly match in the available space
                    ans.push_back(i);
                    i++;
                    changed = true;
                    found = true;
                    break;
                }
                // If neither condition is met, move to the next index in word1
                i++;
            }
            
            // If we couldn't match word2[j], the sequence is invalid
            if (!found) {
                return {};
            }
        }
        
        return ans;
    }
};