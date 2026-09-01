class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int max_energy=energy;
        
        int start_r = -1, start_c = -1;
        int litter_count = 0;
        
        // Grid mapping for litter locations: grid[r][c] -> litter index
        vector<vector<int>> litter_id(m, vector<int>(n, -1));

        // Step 1: Locate starting position 'S' and index each litter 'L'
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (classroom[r][c] == 'S') {
                    start_r = r;
                    start_c = c;
                } else if (classroom[r][c] == 'L') {
                    litter_id[r][c] = litter_count++;
                }
            }
        }

        // If no litter exists, 0 moves are required
        if (litter_count == 0) return 0;

        int target_mask = (1 << litter_count) - 1;

        // Check if starting cell 'S' is on a litter cell
        int start_mask = 0;
        if (litter_id[start_r][start_c] != -1) {
            start_mask |= (1 << litter_id[start_r][start_c]);
        }

        // 3D memoization array: max_energy_seen[r][c][mask]
        // Stores the maximum remaining energy seen at position (r, c) with current bitmask
        vector<vector<vector<int>>> max_energy_seen(
            m, vector<vector<int>>(n, vector<int>(1 << litter_count, -1))
        );

        // Queue tuple: {row, col, mask, remaining_energy, moves}
        queue<vector<int>> q;
        q.push({start_r, start_c, start_mask, max_energy, 0});
        max_energy_seen[start_r][start_c][start_mask] = max_energy;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Step 2: Perform BFS
        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            int r = current[0];
            int c = current[1];
            int mask = current[2];
            int e = current[3];
            int moves = current[4];

            // If all litter items have been collected, return current move count
            if (mask == target_mask) {
                return moves;
            }

            // If energy drops to 0, no further moves can be initiated
            if (e == 0) continue;

            // Explore 4 adjacent neighbors
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                // Boundary & obstacle check
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && classroom[nr][nc] != 'X') {
                    char cell = classroom[nr][nc];

                    // Energy update logic
                    int next_e = (cell == 'R') ? max_energy : e - 1;

                    // Mask update logic
                    int next_mask = mask;
                    if (litter_id[nr][nc] != -1) {
                        next_mask |= (1 << litter_id[nr][nc]);
                    }

                    // Pruning check: visit only if we achieve strictly higher energy for (nr, nc, next_mask)
                    if (next_e > max_energy_seen[nr][nc][next_mask]) {
                        max_energy_seen[nr][nc][next_mask] = next_e;
                        q.push({nr, nc, next_mask, next_e, moves + 1});
                    }
                }
            }
        }

        return -1;
        
    }
};