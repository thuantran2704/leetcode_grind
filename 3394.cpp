#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= merged.back()[1]) { // Merge touching intervals
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            } else {
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> vertical, horizontal;
        for (auto& rect : rectangles) {
            vertical.push_back({rect[1], rect[3]});   // Vertical view (y-coordinates)
            horizontal.push_back({rect[0], rect[2]}); // Horizontal view (x-coordinates)
        }

        vector<vector<int>> mergeH = mergeIntervals(horizontal);
        vector<vector<int>> mergeV = mergeIntervals(vertical);

        return mergeH.size() >= 3 || mergeV.size() >= 3;
    }
};

// Test function
void runTests() {
    Solution sol;

    vector<pair<int, vector<vector<int>>>> testCases = {
        {5, {{1,0,5,2}, {0,2,2,4}, {3,2,5,3}, {0,4,4,5}}}, // Expected: true
        {4, {{0,0,1,1}, {2,0,3,4}, {0,2,2,3}, {3,0,4,3}}}, // Expected: true
        {6, {{0,0,2,2}, {2,0,4,2}, {0,2,4,3}, {0,3,4,5}}}, // Expected: true
        {4, {{0,0,4,2}, {0,2,4,4}}},                      // Expected: false (only one possible cut)
        {3, {{0,0,1,1}, {1,0,2,1}, {2,0,3,1}}},           // Expected: false (no valid cut)
        {5, {{0,0,5,5}}}                                  // Expected: false (only one rectangle)
    };

    for (int i = 0; i < testCases.size(); ++i) {
        int n = testCases[i].first;
        vector<vector<int>> rectangles = testCases[i].second;
        bool result = sol.checkValidCuts(n, rectangles);
        cout << "Test Case " << i + 1 << ": " << (result ? "true" : "false") << endl;
    }
}

// Main function
int main() {
    runTests();
    return 0;
}
