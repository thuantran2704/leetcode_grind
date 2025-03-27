#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int floor = target[0];
        if (n == 0) return floor;
        int count = floor;
        for (int i = 1; i < n; i++) {
            int dif = target[i] - target[i - 1];
            if (dif > 0) {
                count += dif;
            }
        }
        return count;
    }
};

void runTest(vector<int> target, int expected, int testNum) {
    Solution sol;
    int result = sol.minNumberOperations(target);
    cout << "Test " << testNum << ": ";
    if (result == expected) {
        cout << "PASSED ✅\n";
    } else {
        cout << "FAILED ❌ (Expected: " << expected << ", Got: " << result << ")\n";
    }
}

int main() {
    // Test cases
    runTest({3, 1, 5, 4, 2}, 7, 1);
    runTest({1, 1, 1}, 1, 2);
    runTest({4, 2, 8, 3, 6}, 11, 3);
    runTest({1, 2, 3, 4, 5}, 5, 4);
    runTest({5, 4, 3, 2, 1}, 5, 5);
    runTest({7, 7, 7, 7}, 7, 6);
    runTest({10, 1, 10, 1, 10}, 28, 7);
    runTest({1}, 1, 8);
    runTest({}, 0, 9); // Edge case: empty input
    runTest({0, 0, 0}, 0, 10); // Edge case: all zeros

    return 0;
}
