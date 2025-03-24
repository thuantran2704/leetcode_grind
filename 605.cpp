#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        int dist = 2;
        vector<int> closest(m, 0);

        // First pass: Calculate the closest distance to the nearest flower on the left
        for (int i = 0; i < m; i++) {
            if (flowerbed[i] == 1) {
                dist = 0;
            } else {
                dist++;
            }
            closest[i] = dist;
        }

        dist = 2;
        // Second pass: Calculate the closest distance to the nearest flower on the right
        for (int i = m - 1; i >= 0; i--) {
            if (flowerbed[i] == 1) {
                dist = 0;
            } else {
                dist++;
            }
            closest[i] = min(closest[i], dist);
            // If it's possible to place a flower at position i
            if (flowerbed[i] == 0 && closest[i] > 1) {
                n--;  // Decrease the required flowers
                dist = 0;  // Reset distance after placing a flower
            }
        }

        // Return true if all flowers can be placed
        return n <= 0;
    }
};

// Test cases to verify the solution
int main() {
    Solution solution;
    
    vector<vector<int>> testFlowerbeds = {
        {1, 0, 0, 0, 1},     // Example 1
        {1, 0, 0, 0, 0, 1},   // Example 2
        {1, 0, 0, 0, 0, 0, 1},// Example 3
        {0, 0, 0, 0, 0},      // Example 4
        {1, 0, 1, 0, 1}       // Example 5
    };
    
    vector<int> flowerCounts = {1, 1, 2, 3, 1};  // The number of flowers to place for each test case

    for (int i = 0; i < testFlowerbeds.size(); ++i) {
        bool result = solution.canPlaceFlowers(testFlowerbeds[i], flowerCounts[i]);
        cout << "Test case " << i + 1 << ": ";
        cout << (result ? "Can place flowers" : "Cannot place flowers") << endl;
    }

    return 0;
}
