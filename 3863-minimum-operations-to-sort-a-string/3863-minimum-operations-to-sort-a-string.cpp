class Solution {
public:
    int minOperations(string s) {
      int n = s.length();
        
        // 0 operations
        if (std::is_sorted(s.begin(), s.end())) {
            return 0;
        }
        
        // Impossible for length <= 2 if not sorted
        if (n <= 2) {
            return -1;
        }
        
        char min_char = *std::min_element(s.begin(), s.end());
        char max_char = *std::max_element(s.begin(), s.end());
        
        // 1 operation: min is at index 0 or max is at index n-1
        if (s[0] == min_char || s[n - 1] == max_char) {
            return 1;
        }
        
        // Check if min_char exists anywhere in s[0 ... n-2]
        bool min_in_prefix = false;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == min_char) {
                min_in_prefix = true;
                break;
            }
        }
        
        // Check if max_char exists anywhere in s[1 ... n-1]
        bool max_in_suffix = false;
        for (int i = 1; i < n; ++i) {
            if (s[i] == max_char) {
                max_in_suffix = true;
                break;
            }
        }
        
        // Requires 3 operations ONLY if:
        // s[0] is the ONLY place where max_char appears AND
        // s[n-1] is the ONLY place where min_char appears
        if (s[0] == max_char && s[n - 1] == min_char && !min_in_prefix && !max_in_suffix) {
            return 3;
        }
        
        // Otherwise, 2 operations are always enough
        return 2;
    }
};