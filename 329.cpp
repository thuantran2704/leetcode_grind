class Solution {
public:
    vector<vector<int>> dir = {{0,1},{-1,0},{1,0},{0,-1}};
    int ans = 0;

    void explore(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
        int n = matrix.size();
        int m = matrix[0].size();
        if (dp[i][j] != 0) return; // already computed

        int maxPath = 1; // at least itself
        for (int idx = 0; idx < 4; idx++) {
            int x = i + dir[idx][0];
            int y = j + dir[idx][1];
            if (x >= 0 && y >= 0 && x < n && y < m && matrix[x][y] > matrix[i][j]) {
                if (dp[x][y] == 0) explore(matrix, dp, x, y);
                maxPath = max(maxPath, 1 + dp[x][y]);
            }
        }

        dp[i][j] = maxPath;
        ans = max(ans, maxPath);
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0)); // 0 = unvisited

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i][j] == 0) {
                    explore(matrix, dp, i, j);
                }
            }
        }

        return ans;
    }
};
