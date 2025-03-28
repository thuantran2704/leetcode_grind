#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Find the dominant element using Boyer-Moore Voting Algorithm
        pair<int, int> ans = {nums[0], 1};
        
        for (int i = 1; i < n; i++) {
            if (nums[i] == ans.first) {
                ans.second++;
            } else {
                ans.second--;
                if (ans.second == 0) {
                    ans = {nums[i], 1};
                }
            }
        }
        
        int dominant = ans.first;

        // Step 2: Precompute prefix counts for the dominant element
        vector<int> prefix(n + 1, 0);  // prefix[i] will store the count of dominant element in nums[0, ..., i-1]
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + (nums[i - 1] == dominant);
        }

        // Step 3: Check for the valid split
        for (int i = 0; i < n - 1; i++) {
            // Count of dominant elements in the left part (nums[0, ..., i])
            int leftCount = prefix[i + 1];
            
            // Count of dominant elements in the right part (nums[i+1, ..., n-1])
            int rightCount = prefix[n] - prefix[i + 1];
            
            // Check if both parts have more than half of the dominant element
            if (leftCount > (i + 1) / 2 && rightCount > (n - i - 1) / 2) {
                return i;  // valid split at index i
            }
        }

        return -1;  // no valid split exists
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Typical case with a valid split
    vector<int> test1 = {1, 1, 2, 2, 1, 1, 2};
    cout << "Test case 1 result: " << solution.minimumIndex(test1) << endl;  // Expected output: 3

    // Test case 2: Only one element, no split possible
    vector<int> test2 = {1};
    cout << "Test case 2 result: " << solution.minimumIndex(test2) << endl;  // Expected output: -1
    
    // Test case 3: No valid split (dominant element doesn't allow a valid split)
    vector<int> test3 = {1, 1, 2, 2, 2, 1};
    cout << "Test case 3 result: " << solution.minimumIndex(test3) << endl;  // Expected output: -1
    
    // Test case 4: Simple case with two possible splits
    vector<int> test4 = {3, 3, 3, 4, 4, 4, 3};
    cout << "Test case 4 result: " << solution.minimumIndex(test4) << endl;  // Expected output: 3

    // Test case 5: Edge case with a large array (valid split in the middle)
    vector<int> test5(1000000, 1); // Fill with 1s
    for (int i = 500000; i < 1000000; i++) {
        test5[i] = 2; // Change half of the elements to 2
    }
    cout << "Test case 5 result: " << solution.minimumIndex(test5) << endl;  // Expected output: 499999 (valid split)

    return 0;
}
