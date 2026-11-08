class Solution {
public:
 int largestAltitude(vector<int>& gain) {
        int max_altitude = 0;
        int current_altitude = 0;

        for (int g : gain) {
            current_altitude += g;
            max_altitude = max(max_altitude, current_altitude);
        }

        return max_altitude;
    }
};
    int largestAltitude(vector<int>& gain) {
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    vector<int> gain1 = {-5, 1, 5, 0, -7};
    cout << "Example 1 Output: " << sol.largestAltitude(gain1) << "\n"; // Output: 1

    vector<int> gain2 = {-4, -3, -2, -1, 4, 3, 2};
    cout << "Example 2 Output: " << sol.largestAltitude(gain2) << "\n"; // Output: 0
    return 0;
    }
