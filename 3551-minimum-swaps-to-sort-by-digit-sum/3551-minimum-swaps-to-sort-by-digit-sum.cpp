class Solution {
 private:
    int getDigitSum(int n) {
        n = abs(n);
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int countCycles(const vector<int>& p) {
        int n = p.size();
        vector<bool> visited(n, false);
        int cycle_count = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                cycle_count++;
                int curr = i;
                while (!visited[curr]) {
                    visited[curr] = true;
                    curr = p[curr];
                }
            }
        }

        return cycle_count;
    }
public:
    int minSwaps(vector<int>& nums) {
   int n = nums.size();

        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end(), [this](int a, int b) {
            int sumA = getDigitSum(a);
            int sumB = getDigitSum(b);
            if (sumA != sumB) return sumA < sumB;
            return a < b;
        });

        unordered_map<int, int> target_idx;
        for (int i = 0; i < n; ++i) {
            target_idx[sorted_nums[i]] = i;
        }

        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            p[i] = target_idx[nums[i]];
        }

        return n - countCycles(p);
    
    }
};