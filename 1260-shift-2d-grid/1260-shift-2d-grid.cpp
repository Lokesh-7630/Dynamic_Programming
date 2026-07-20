class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total_elements = m * n;
        
        // Optimize k to handle rotations larger than the total element count
        k = k % total_elements;
        
        // Create a result grid filled with 0s matching original dimensions
        std::vector<std::vector<int>> result(m, std::vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 1. Convert 2D coordinates to a 1D flat index
                int flat_index = i * n + j;
                
                // 2. Shift the index and wrap around using modulo
                int new_flat_index = (flat_index + k) % total_elements;
                
                // 3. Convert back to 2D coordinates for the result grid
                int new_i = new_flat_index / n;
                int new_j = new_flat_index % n;
                
                result[new_i][new_j] = grid[i][j];
            }
        }
        
        return result;
    }
};