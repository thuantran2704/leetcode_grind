class Solution {
public:
    int code(int i, int j){
        return 50*i + j;
    }
    pair<int,int> decode(int x){
        return {x / 50, x % 50};
    }
    int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> res(n, vector<int>(n, 0)); // visited marker
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({grid[0][0], 0});
    res[0][0] = 1;  // visited at start

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        int time = cur.first;
        auto [i, j] = decode(cur.second);
        if(i == n-1 && j == n-1) return time;

        vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        for(auto& d : directions) {
            int ni = i + d.first, nj = j + d.second;
            if(ni >= 0 && ni < n && nj >= 0 && nj < n && res[ni][nj] == 0) {
                res[ni][nj] = 1; // mark visited here
                pq.push({max(time, grid[ni][nj]), code(ni, nj)});
            }
        }
    }
    return 0;
}

};