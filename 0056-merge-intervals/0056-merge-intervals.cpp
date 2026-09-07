class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       if (intervals.empty()) return {};

        // Sort intervals by their start times
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> merged;

        for (const auto& interval : intervals) {
            // If merged is empty or no overlap with the last interval
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } else {
                // Overlap exists: update the end time of the last interval
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }
};