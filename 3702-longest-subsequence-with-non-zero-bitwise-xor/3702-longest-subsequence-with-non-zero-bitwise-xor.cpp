class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXor = 0;
        bool hasNonZero = false;
        
        for (int num : nums) {
            totalXor ^= num;
            if (num != 0) {
                hasNonZero = true;
            }
        }
        
        // Scenario 1
        if (totalXor != 0) return nums.size();
        
        // Scenario 2
        if (!hasNonZero) return 0;
        
        // Scenario 3
        return nums.size() - 1;
    }
};