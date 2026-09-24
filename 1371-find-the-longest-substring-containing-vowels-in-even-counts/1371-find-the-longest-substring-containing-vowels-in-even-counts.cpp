class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> seen(32, -2);
        
        // Base case: Mask 0 (all vowels even) is seen at index -1
        seen[0] = -1;
        
        int mask = 0;
        int maxLength = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            
            // Flip the corresponding bit if character is a vowel
            if (c == 'a') mask ^= 1;       // Bit 0
            else if (c == 'e') mask ^= 2;  // Bit 1
            else if (c == 'i') mask ^= 4;  // Bit 2
            else if (c == 'o') mask ^= 8;  // Bit 3
            else if (c == 'u') mask ^= 16; // Bit 4
            
            // If this mask state was seen before, compute valid substring length
            if (seen[mask] != -2) {
                maxLength = max(maxLength, i - seen[mask]);
            } else {
                // Record the FIRST index where this mask state was encountered
                seen[mask] = i;
            }
        }
        
        return maxLength;
    }
};