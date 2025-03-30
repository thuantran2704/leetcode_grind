#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    bool bfs(vector<vector<int>>& grid, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 1){
            return false;
        }
        grid[i][j] = 2;
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        deque<pair<int,int>> dq;
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    dq.push_back({i,j});
                } else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        
        int time = 0;
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!dq.empty() && fresh > 0){
            int k = dq.size();
            time++;
            for(int t = 0; t < k; t++){
                pair<int,int> temp = dq.front();
                dq.pop_front();
                int i = temp.first;
                int j = temp.second;
                for(int idx = 0; idx < 4; idx++){
                    int ni = i + dir[idx].first;
                    int nj = j + dir[idx].second;
                    if(bfs(grid,ni,nj)){
                        fresh--;
                        dq.push_back({ni,nj});
                    }
                }
            }
        }
        return fresh == 0 ? time : -1;
    }
};

void runTest(vector<vector<int>> grid, int expected) {
    Solution sol;
    int result = sol.orangesRotting(grid);
    cout << "Result: " << result << " | Expected: " << expected << (result == expected ? " | Pass" : " | Fail") << endl;
}

int main() {
    Solution sol;
    
    // Test Case 1: Basic Case
    runTest({{2,1,1},{1,1,0},{0,1,1}}, 4);
    
    // Test Case 2: No fresh oranges
    runTest({{0,2}}, 0);
    
    // Test Case 3: Impossible to rot all oranges
    runTest({{0,1}}, -1);
    
    // Test Case 4: Already rotten oranges only
    runTest({{2,2,2},{2,2,2}}, 0);
    
    // Test Case 5: Multiple separate fresh oranges
    runTest({{2,1,1},{0,1,1},{1,0,1}}, -1);
    
    // Test Case 6: All fresh oranges
    runTest({{1,1,1},{1,1,1}}, -1);
    
    // Test Case 7: Large grid with gradual rotting
    runTest({{2,1,0,1},{1,1,0,1},{0,1,1,1},{1,0,1,2}}, 3);
    
    return 0;
}