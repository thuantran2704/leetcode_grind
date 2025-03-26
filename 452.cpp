#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        // Sort by end coordinate
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1;
        int prevEnd = points[0][1];

        for (const auto& balloon : points) {
            if (balloon[0] > prevEnd) { // If it starts after the last arrow
                arrows++;
                prevEnd = balloon[1]; // Shoot a new arrow
            }
        }

        return arrows;
    }
};

// Test cases
void runTest(vector<vector<int>> points, int expected) {
    Solution sol;
    int result = sol.findMinArrowShots(points);
    cout << "Test case result: " << (result == expected ? "PASSED" : "FAILED") 
         << " | Output: " << result << " | Expected: " << expected << endl;
}

int main() {
    runTest({{10,16}, {2,8}, {1,6}, {7,12}}, 2);
    runTest({{1,2}, {3,4}, {5,6}, {7,8}}, 4);
    runTest({{1,2}, {2,3}, {3,4}, {4,5}}, 2);
    runTest({{1,10}, {2,3}, {4,5}, {6,7}, {8,9}}, 1);
    return 0;
}
