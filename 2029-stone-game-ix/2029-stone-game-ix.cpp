class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
       int cnt[3] = {0, 0, 0};
        
        // Count frequencies of remainders
        for (int stone : stones) {
            cnt[stone % 3]++;
        }
        
        // Case 1: Even number of 0s
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        } 
        // Case 2: Odd number of 0s
        else {
            return abs(cnt[1] - cnt[2]) > 2;
        }
    }
};