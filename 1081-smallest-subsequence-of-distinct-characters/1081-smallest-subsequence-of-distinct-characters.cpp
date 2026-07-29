class Solution {
public:
    string smallestSubsequence(string s) {
           vector<int> last_idx(26, 0);
        
        // in_stack keeps track of whether a character is currently in our result string.
        // We only want EXACTLY ONE of each distinct character.
        vector<bool> in_stack(26, false);
        
        // We will use a string to act as our monotonic stack. 
        // This is efficient and avoids having to convert a stack back to a string later.
        string result = "";

        // Pass 1: Record the last occurrence of each character.
        for (int i = 0; i < s.length(); i++) {
            last_idx[s[i] - 'a'] = i;
        }

        // Pass 2: Build the lexicographically smallest subsequence.
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            
            // If the character is already in our result stack, we skip it.
            // We only need exactly one of each distinct character.
            if (in_stack[c - 'a']) {
                continue;
            }

            // Core Monotonic Stack Logic:
            // 1. result is not empty
            // 2. The last character in result is alphabetically GREATER than current character 'c'
            // 3. We have another copy of that last character appearing later in the string
            while (!result.empty() && result.back() > c && last_idx[result.back() - 'a'] > i) {
                // It is safe to pop this character and add it back later.
                in_stack[result.back() - 'a'] = false;
                result.pop_back();
            }

            // Push the current character onto our result stack and mark it as seen.
            result.push_back(c);
            in_stack[c - 'a'] = true;
        }

        return result;
    }
};