#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        
        // Arrays to store the maximum values to the left and right of each element
        vector<int> left(n, 0), right(n, 0);
        
        // Max values to the left
        int max_left = nums[0]; // Initialize with the first element
        for (int i = 1; i < n; i++) {
            left[i] = max_left; // Store the max value to the left of i
            max_left = max(max_left, nums[i]); // Update the max value to the left
        }
        
        // Max values to the right
        int max_right = nums[n-1]; // Initialize with the last element
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max_right; // Store the max value to the right of i
            max_right = max(max_right, nums[i]); // Update the max value to the right
        }
        
        // Now calculate the triplet value
        for (int i = 1; i < n - 1; i++) {
            if (left[i] > nums[i] && right[i] > 0) {  // We want to ensure there's a valid triplet
                ans = max(ans, (long long)(left[i] - nums[i]) * right[i]);
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Basic case with increasing numbers
    vector<int> nums1 = {1, 2, 3, 4, 5};
    cout << "Test Case 1: " << sol.maximumTripletValue(nums1) << endl;  // Expected output: 6

    // Test Case 2: Decreasing numbers
    vector<int> nums2 = {5, 4, 3, 2, 1};
    cout << "Test Case 2: " << sol.maximumTripletValue(nums2) << endl;  // Expected output: 0

    // Test Case 3: All elements are the same
    vector<int> nums3 = {2, 2, 2, 2, 2};
    cout << "Test Case 3: " << sol.maximumTripletValue(nums3) << endl;  // Expected output: 0

    // Test Case 4: Random mixed values
    vector<int> nums4 = {1, 5, 2, 3, 4};
    cout << "Test Case 4: " << sol.maximumTripletValue(nums4) << endl;  // Expected output: 6

    // Test Case 5: Large case with alternating high and low values
    vector<int> nums5 = {10, 1, 10, 1, 10, 1};
    cout << "Test Case 5: " << sol.maximumTripletValue(nums5) << endl;  // Expected output: 90

    // Test Case 6: Smallest possible case with only 3 elements
    vector<int> nums6 = {3, 1, 4};
    cout << "Test Case 6: " << sol.maximumTripletValue(nums6) << endl;  // Expected output: 3

    return 0;
}
