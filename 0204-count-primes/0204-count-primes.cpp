class Solution {
public:
    int countPrimes(int n) {
       if (n <= 2) return 0;

        // Use vector<char> instead of vector<bool> for faster direct byte access
        vector<char> isPrime(n, true);
        int count = n / 2; // Assume all odd numbers >= 3 are prime initially

        for (int p = 3; p * p < n; p += 2) {
            if (isPrime[p]) {
                // Mark odd multiples starting from p * p, step by 2 * p to skip even multiples
                for (int i = p * p; i < n; i += 2 * p) {
                    if (isPrime[i]) {
                        isPrime[i] = false;
                        count--; // Decrement prime count directly
                    }
                }
            }
        }

        return count;
    }
};