class Solution {
public:
    int minOperations(vector<int>& nums) {
     int n = nums.size();
        if (n <= 1) return 0;

        int idx_zero = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                idx_zero = i;
                break;
            }
        }

        // Check if array is an increasing cyclic shift
        bool is_increasing = true;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != (nums[idx_zero] + (i - idx_zero + n) % n) % n) {
                is_increasing = false;
                break;
            }
        }

        if (is_increasing) {
            // Option 1: Rotate left idx_zero times
            // Option 2: Reverse (1) + rotate left (n - idx_zero) times + reverse (1) -> n - idx_zero + 2
            return min(idx_zero, n - idx_zero + 2);
        }

        // Check if array is a decreasing cyclic shift
        bool is_decreasing = true;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != (nums[idx_zero] - (i - idx_zero) + n) % n) {
                is_decreasing = false;
                break;
            }
        }

        if (is_decreasing) {
            // Option 1: Rotate left (idx_zero + 1) times + reverse (1) -> idx_zero + 2
            // Option 2: Reverse (1) + rotate left (n - 1 - idx_zero) times -> n - idx_zero
            return min(idx_zero + 2, n - idx_zero);
        }

        return -1;
    }
};