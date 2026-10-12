class Solution {
public:
    int minInsertions(string s) {
        int res = 0;
        int right_needed = 0;

        for (char c : s) {
            if (c == '(') {
                // If we need an odd number of ')', insert one ')' to complete the previous pair
                if (right_needed % 2 != 0) {
                    res++;
                    right_needed--;
                }
                right_needed += 2;
            } else { // c == ')'
                right_needed--;
                // If we have an unmatched ')', insert an opening '('
                if (right_needed < 0) {
                    res++;            // Insert '('
                    right_needed = 1;  // ' (' supplies two ')', so 2 - 1 = 1 remaining ')' needed
                }
            }
        }

        return res + right_needed;
    }
};