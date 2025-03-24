#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_length = 1;
        int left = 0;
        int used_bits = 0;
        
        for (int right = 0; right < n; ++right) {
            // If there's an overlap, move the left pointer to the right
            while ((used_bits & nums[right]) != 0) {
                used_bits ^= nums[left];
                ++left;
            }
            
            used_bits |= nums[right];  // Add the current number's bits to the used set
            max_length = max(max_length, right - left + 1);  // Update the max length
        }
        
        return max_length;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {1, 3, 8, 48, 10};
    cout << "Test case 1: " << solution.longestNiceSubarray(nums1) << endl;  // Expected output: 3
    
    // Test case 2
    vector<int> nums2 = {3, 1, 5, 11, 13};
    cout << "Test case 2: " << solution.longestNiceSubarray(nums2) << endl;  // Expected output: 4
    
    // Test case 3
    vector<int> nums3 = {1, 3, 8, 48, 10, 12};
    cout << "Test case 3: " << solution.longestNiceSubarray(nums3) << endl;  // Expected output: 4
    
    // Test case 4 (Edge case with empty array)
    vector<int> nums4 = {};
    cout << "Test case 4: " << solution.longestNiceSubarray(nums4) << endl;  // Expected output: 0
    
    // Test case 5 (Edge case with only one element)
    vector<int> nums5 = {5};
    cout << "Test case 5: " << solution.longestNiceSubarray(nums5) << endl;  // Expected output: 1
    
    return 0;
}
