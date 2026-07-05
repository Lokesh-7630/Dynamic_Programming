class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        // len[i] stores the length of LIS ending at index i
        // count[i] stores the number of LIS ending at index i
        vector<int> len(n, 1);
        vector<int> count(n, 1);

        int max_len = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (len[j] + 1 > len[i]) {
                        // Found a strictly longer increasing subsequence
                        len[i] = len[j] + 1;
                        count[i] = count[j];
                    } else if (len[j] + 1 == len[i]) {
                        // Found another subsequence of the same maximum length
                        count[i] += count[j];
                    }
                }
            }
            max_len = std::max(max_len, len[i]);
        }

        int total_lis = 0;
        for (int i = 0; i < n; i++) {
            if (len[i] == max_len) {
                total_lis += count[i];
            }
        }

        return total_lis;
    }
};