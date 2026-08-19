class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reservedRows;

        // Map reserved seats (2-9) to bitwise positions
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col >= 2 && col <= 9) {
                reservedRows[row] |= (1 << (col - 2));
            }
        }

        // Start with max capacity assuming all rows are empty
        int maxGroups = n * 2;

        for (const auto& [row, mask] : reservedRows) {
            bool leftPossible   = (mask & 0b00001111) == 0; // Seats 2,3,4,5
            bool middlePossible = (mask & 0b00111100) == 0; // Seats 4,5,6,7
            bool rightPossible  = (mask & 0b11110000) == 0; // Seats 6,7,8,9

            if (leftPossible && rightPossible) {
                // Fits 2 groups (no adjustment needed for this row)
                continue;
            } else if (leftPossible || rightPossible || middlePossible) {
                // Fits 1 group instead of 2
                maxGroups -= 1;
            } else {
                // Fits 0 groups instead of 2
                maxGroups -= 2;
            }
        }

        return maxGroups;
    }
};