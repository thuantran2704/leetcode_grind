#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int>& v) {
    if (v.empty()) {
        cout << "No valid order exists.\n";
        return;
    }
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Test Case 1: Simple Valid Order
    vector<vector<int>> prerequisites1 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<int> result1 = sol.findOrder(4, prerequisites1);
    cout << "Test Case 1: ";
    printVector(result1);  // Expected output: 0 1 2 3 (or equivalent valid order)

    // Test Case 2: No prerequisites, any order is valid
    vector<vector<int>> prerequisites2 = {};
    vector<int> result2 = sol.findOrder(3, prerequisites2);
    cout << "Test Case 2: ";
    printVector(result2);  // Expected output: Any permutation of {0, 1, 2}

    // Test Case 3: Circular dependency (no valid order)
    vector<vector<int>> prerequisites3 = {{0, 1}, {1, 2}, {2, 0}};
    vector<int> result3 = sol.findOrder(3, prerequisites3);
    cout << "Test Case 3: ";
    printVector(result3);  // Expected output: No valid order exists.

    // Test Case 4: Single Course
    vector<vector<int>> prerequisites4 = {};
    vector<int> result4 = sol.findOrder(1, prerequisites4);
    cout << "Test Case 4: ";
    printVector(result4);  // Expected output: 0

    // Test Case 5: All courses depend on one
    vector<vector<int>> prerequisites5 = {{1, 0}, {2, 0}, {3, 0}, {4, 0}};
    vector<int> result5 = sol.findOrder(5, prerequisites5);
    cout << "Test Case 5: ";
    printVector(result5);  // Expected output: 0 1 2 3 4 (or any valid order)

    return 0;
}
