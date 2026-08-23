class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine sign using XOR: true if signs differ
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Convert to absolute values using 64-bit to prevent overflow
        long long a = std::labs(dividend);
        long long b = std::labs(divisor);
        long long quotient = 0;

        // Iterate through all 32 bit positions from most significant to least
        for (int i = 31; i >= 0; --i) {
            // Check if (b * 2^i) fits inside the remaining dividend
            if ((a >> i) >= b) {
                quotient += (1LL << i); // Set the i-th bit in the quotient
                a -= (b << i);          // Subtract (b * 2^i) from dividend
            }
        }

        return isNegative ? -quotient : quotient;
    }
};