class Solution {
public:
    int longestStrChain(vector<string>& words) {
       std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
            return a.length() < b.length();
        });
        
        // Maps a word to the longest chain ending at that word
        std::unordered_map<std::string, int> dp;
        int max_chain = 1;
        
        for (const std::string& word : words) {
            int current_longest = 1;
            
            // Try removing each character to find a potential predecessor
            for (int i = 0; i < word.length(); ++i) {
                std::string predecessor = word.substr(0, i) + word.substr(i + 1);
                
                if (dp.count(predecessor)) {
                    current_longest = std::max(current_longest, dp[predecessor] + 1);
                }
            }
            
            dp[word] = current_longest;
            max_chain = std::max(max_chain, current_longest);
        }
        
        return max_chain; 
    }
};