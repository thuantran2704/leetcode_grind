#include <iostream>
#include <vector>

//this is from neetode.io, graph
using namespace std;

void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution solution;

    vector<vector<int>> grid = {
        {2147483647, -1, 0, 2147483647},
        {2147483647, 2147483647, 2147483647, -1},
        {2147483647, -1, 2147483647, -1},
        {0, -1, 2147483647, 2147483647}
    };

    cout << "Original Grid:" << endl;
    printGrid(grid);

    solution.islandsAndTreasure(grid);

    cout << "\nUpdated Grid:" << endl;
    printGrid(grid);

    return 0;
}
