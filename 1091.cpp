class Solution {
    public:
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
            int n = grid.size();
            // Check if the start or the end cell is blocked.
            if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;
            
            // Directions (8-connected neighbors)
            vector<vector<int>> directions = {
                {1, 0}, {-1, 0}, {0, 1}, {0, -1},
                {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
            };
            
            // Use a queue for BFS. The starting cell is (0,0)
            queue<pair<int, int>> q;
            q.push({0, 0});
            grid[0][0] = 1; // Mark as visited and store the path length
            
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();
                
                // If we reached the bottom-right cell, return the path length
                if (r == n - 1 && c == n - 1)
                    return grid[r][c];
                    
                // Explore all 8 neighbors
                for (auto& d : directions) {
                    int nr = r + d[0], nc = c + d[1];
                    // Check bounds and if the cell is unvisited and not blocked
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                        q.push({nr, nc});
                        // Update with the new path length and mark as visited
                        grid[nr][nc] = grid[r][c] + 1;
                    }
                }
            }
            
            return -1; // No valid path exists
        }
    };
    