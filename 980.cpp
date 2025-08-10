class Solution {
    public:
        int backtrack(vector<vector<int>>& grid, int step, int i, int j){
            int n = grid.size();
            int m = grid[0].size();
            vector<pair<int,int>> dir = {{-1,0},{0,-1},{0,1},{1,0}};
            if(i < 0 || i >= n || j < 0 || j >= m) return 0;
            if(grid[i][j] == 2 && step == 0) return 1;
            else if(grid[i][j] != 0) return 0;
            grid[i][j] = -1;
            int ans = 0;
            for(auto& d: dir){
                ans += backtrack(grid, step - 1, i + d.first, j + d.second);
            }
            grid[i][j] = 0;
            return ans;
        }
        int uniquePathsIII(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            int si = 0;
            int sj = 0;
            int obs = 0;
            for(int i = 0 ; i < n;i++){
                for(int j = 0 ; j < m;j++){
                    if(grid[i][j] == 1){
                        si = i;
                        sj = j;
                    }
                    if(grid[i][j] == -1){
                        obs++;
                    }
                }
            }
            grid[si][sj] = -1;
            return backtrack(grid, m*n - obs-1, si, sj);
        }
    };