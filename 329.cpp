class Solution {
    public:
        int longestIncreasingPath(vector<vector<int>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();
            vector<vector<int>> memo(n, vector<int>(m, 0));
            vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
            
            function<int(int, int)> dfs = [&](int i, int j) -> int {
                if (memo[i][j] != 0) return memo[i][j];
    
                int maxLen = 1;  // path includes itself
                for (auto& dir : dirs) {
                    int ni = i + dir[0], nj = j + dir[1];
                    if (ni >= 0 && nj >= 0 && ni < n && nj < m && matrix[ni][nj] > matrix[i][j]) {
                        maxLen = max(maxLen, 1 + dfs(ni, nj));
                    }
                }
    
                memo[i][j] = maxLen;
                return maxLen;
            };
    
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    ans = max(ans, dfs(i, j));
                }
            }
    
            return ans;
        }
    };