class Solution {
private:
    int n;
    vector<long long> pref;
    vector<long long> dp_prev;
    vector<long long> dp_curr;

    // Helper function to calculate the cost of a subarray from index l to r (0-indexed)
    long long get_cost(int l, int r) {
        long long sumArr = pref[r + 1] - pref[l];
        return sumArr * (sumArr + 1) / 2;
    }

    // Divide and Conquer DP optimization function
    void compute(int l, int r, int optL, int optR) {
        if (l > r) return;

        int mid = l + (r - l) / 2;
        int best_idx = -1;
        dp_curr[mid] = -1; // Represents infinity

        // The transition point can only go up to mid because a subarray must contain at least 1 element
        for (int i = optL; i <= min(mid, optR); ++i) {
            long long current_cost = (i == 0 ? 0 : dp_prev[i - 1]) + get_cost(i, mid);
            if (dp_curr[mid] == -1 || current_cost < dp_curr[mid]) {
                dp_curr[mid] = current_cost;
                best_idx = i;
            }
        }

        // Recursively compute for left and right halves
        compute(l, mid - 1, optL, best_idx);
        compute(mid + 1, r, best_idx, optR);
    }
public:
    long long minPartitionScore(vector<int>& nums, int k) {
        n = nums.size();
        pref.assign(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + nums[i];
        }

        // dp_prev[i] stores the minimum score to partition prefix nums[0...i] into `j` parts
        dp_prev.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            dp_prev[i] = get_cost(0, i);
        }

        // Iteratively compute for 2 parts up to k parts
        for (int j = 2; j <= k; ++j) {
            dp_curr.assign(n, 0);
            compute(0, n - 1, 0, n - 1);
            dp_prev = move(dp_curr);
        }

        return dp_prev[n - 1];
    }
};