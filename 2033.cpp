#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int v = grid.size(), h = grid[0].size();
        if (v == 0 || h == 0) return 0;
        
        int mod = grid[0][0] % x;
        vector<int> arr(v * h, 0);
        
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < h; j++) {
                arr[i * h + j] = grid[i][j];
                if (grid[i][j] % x != mod) {
                    return -1;
                }
            }
        }
        
        sort(arr.begin(), arr.end());
        int median = arr[(v * h) / 2];
        int count = 0;
        
        for (int i = 0; i < v * h; i++) {
            count += abs(median - arr[i]) / x;
        }
        
        return count;
    }
};

void runTest(vector<vector<int>> grid, int x, int expected) {
    Solution sol;
    int result = sol.minOperations(grid, x);
    cout << "Test case result: " << (result == expected ? "PASSED" : "FAILED") << " | Output: " << result << " | Expected: " << expected << endl;
}

int main() {
    // Test cases
    runTest({{2, 4}, {6, 8}}, 2, 4);
    runTest({{1, 5}, {2, 3}}, 1, -1);
    runTest({{3, 3, 3}, {3, 3, 3}}, 3, 0);
    runTest({{1}}, 1, 0);
    runTest({{1, 2}, {3, 4}}, 2, -1);
    
    return 0;
}
