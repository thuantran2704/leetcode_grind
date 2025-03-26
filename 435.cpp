#include <iostream>
#include <vector>
#include <algorithm>

//gosh I was dumb
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n < 2) return 0;
        
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        
        int remove = 0, prevEnd = intervals[0][1];
        
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < prevEnd) {
                remove++;
            } else {
                prevEnd = intervals[i][1];
            }
        }
        
        return remove;
    }
};

void runTest(vector<vector<int>> intervals, int expected) {
    Solution sol;
    int result = sol.eraseOverlapIntervals(intervals);
    cout << "Test case result: " << (result == expected ? "PASSED" : "FAILED") << " | Output: " << result << " | Expected: " << expected << endl;
}

int main() {
    // Test cases
    runTest({{1, 2}, {2, 3}, {3, 4}, {1, 3}}, 1);
    runTest({{1, 2}, {1, 2}, {1, 2}}, 2);
    runTest({{1, 2}, {2, 3}}, 0);
    runTest({{1, 5}, {2, 3}, {3, 4}, {4, 6}}, 1);
    
    return 0;
}
