class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int validIslandsCount = 0;

        // 4-directional offsets: up, down, left, right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Helper DFS lambda function to traverse an island
        auto dfs = [&](auto& self, int r, int c) -> long long {
            long long sum = grid[r][c];
            grid[r][c] = 0; // Mark as visited in-place

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0) {
                    sum += self(self, nr, nc);
                }
            }
            return sum;
        };

        // Traverse each cell in the grid
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] > 0) {
                    long long islandTotalValue = dfs(dfs, r, c);
                    if (islandTotalValue % k == 0) {
                        validIslandsCount++;
                    }
                }
            }
        }

        return validIslandsCount;
    }
};