#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // Ensure mid is even to compare it with the next element
            if (mid % 2 == 1) {
                mid--;  // Move mid to an even index for comparison
            }

            if (nums[mid] == nums[mid + 1]) {
                left = mid + 2;  // The single element is in the right half
            } else {
                right = mid;  // The single element is in the left half
            }
        }

        return nums[left];  // left will point to the unique element
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "Test Case 1: " << sol.singleNonDuplicate(nums1) << endl; // Expected output: 2

    // Test Case 2
    vector<int> nums2 = {3};
    cout << "Test Case 2: " << sol.singleNonDuplicate(nums2) << endl; // Expected output: 3

    // Test Case 3
    vector<int> nums3 = {1, 1, 2, 2, 3, 3, 4, 4, 5};
    cout << "Test Case 3: " << sol.singleNonDuplicate(nums3) << endl; // Expected output: 5

    // Test Case 4
    vector<int> nums4 = {10, 10, 20, 20, 30, 40, 40};
    cout << "Test Case 4: " << sol.singleNonDuplicate(nums4) << endl; // Expected output: 30

    // Test Case 5
    vector<int> nums5 = {1, 1, 2, 3, 3};
    cout << "Test Case 5: " << sol.singleNonDuplicate(nums5) << endl; // Expected output: 2

    // Test Case 6
    vector<int> nums6 = {1000000000, 1000000000, 2000000000, 2000000000, 3000000000};
    cout << "Test Case 6: " << sol.singleNonDuplicate(nums6) << endl; // Expected output: 3000000000

    return 0;
}
