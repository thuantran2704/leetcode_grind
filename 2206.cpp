#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        for (auto entry : freq) {
            if (entry.second % 2 != 0) {
                return false;
            }
        }
        return true;
    }
};

// Test function
void runTests() {
    Solution sol;

    vector<vector<int>> testCases = {
        {3, 3, 2, 2, 2, 2},    // Expected: true
        {1, 2, 3, 4},          // Expected: false
        {1, 1, 2, 2, 3, 3},    // Expected: true
        {5, 5, 5, 5, 5, 5},    // Expected: true
        {10, 10, 20, 20, 30},  // Expected: false
        {},                    // Expected: true (empty array case)
        {42, 42}               // Expected: true (single pair)
    };

    for (int i = 0; i < testCases.size(); ++i) {
        bool result = sol.divideArray(testCases[i]);
        cout << "Test Case " << i + 1 << ": " << (result ? "true" : "false") << endl;
    }
}

// Main function
int main() {
    runTests();
    return 0;
}
