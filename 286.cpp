
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>> dirs = {{0,-1},{-1,0},{1,0},{0,1}};
        queue<pair<int,int>> qp;
        for(int i = 0 ; i < n;i++){
            for(int j = 0 ; j < m;j++){
                if(grid[i][j] == 0){                    
                    qp.push({i,j});
                }
            }
        }
       while(!qp.empty()){
            auto [x,y] = qp.front();
            qp.pop();
            
            for(auto& d : dirs){
                int nx = x + d.first;
                int ny = y + d.second;
                if(nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] == -1) continue;
                
                // Only update if we found shorter distance
                if(grid[nx][ny] > grid[x][y] + 1){
                    grid[nx][ny] = grid[x][y] + 1;
                    qp.push({nx,ny});
                }
            }
       }
    }
};