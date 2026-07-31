class Solution {
public:
    int minimumPushes(string word) {
    std::vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        
        // Step 2: Sort frequencies in descending order
        std::sort(freq.rbegin(), freq.rend());
        
        // Step 3: Accumulate total pushes
        int totalPushes = 0;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] == 0) break; // No more unique characters present
            
            // i / 8 maps rank to press cost:
            // i = 0..7   -> cost = 1
            // i = 8..15  -> cost = 2
            // i = 16..23 -> cost = 3
            // i = 24..25 -> cost = 4
            int pressCost = (i / 8) + 1;
            totalPushes += freq[i] * pressCost;
        }
        
        return totalPushes;
    }
};