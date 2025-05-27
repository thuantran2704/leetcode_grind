class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0}); // {reach, i, j}
        moveTime[0][0] = 0;

        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int reach = cur[0];
            int i = cur[1];
            int j = cur[2];

            if (reach >= time[i][j]) continue;
            if (i == n - 1 && j == m - 1) return reach;
            time[i][j] = reach;

            for (auto& d : dir) {
                int x = i + d[0];
                int y = j + d[1];
                if (x >= 0 && y >= 0 && x < n && y < m && time[x][y] == INT_MAX) {
                    int t = max(moveTime[x][y], reach) + 1;
                    pq.push({t, x, y});
                }
            }
        }
        return -1;
    }
};