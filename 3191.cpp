#include <iostream>
#include <vector>

using namespace std;
//needs revisit some day, the concept is simple yet was
//quite some out of the box thinking
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        // First loop to check and flip values
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] == 0) {
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                count++;
            }
        }

        // Second loop to check if all elements are 1
        for (int i = 0; i < n; i++) {
            if (nums[i] != 1) {
                return -1; // Return -1 if it's impossible to convert all to 1
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> test1 = {0, 0, 0, 0, 0};
    cout << "Test Case 1: " << sol.minOperations(test1) << endl; // Expected output: 2
    
    // Test Case 2
    vector<int> test2 = {1, 1, 1, 0, 0};
    cout << "Test Case 2: " << sol.minOperations(test2) << endl; // Expected output: 1
    
    // Test Case 3
    vector<int> test3 = {0, 1, 0, 0, 0};
    cout << "Test Case 3: " << sol.minOperations(test3) << endl; // Expected output: 1
    
    // Test Case 4 - Impossible case
    vector<int> test4 = {0, 1, 1, 0, 1};
    cout << "Test Case 4: " << sol.minOperations(test4) << endl; // Expected output: -1
    
    // Test Case 5 - Already all 1s
    vector<int> test5 = {1, 1, 1, 1, 1};
    cout << "Test Case 5: " << sol.minOperations(test5) << endl; // Expected output: 0
    
    return 0;
}
