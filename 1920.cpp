class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == i) continue;  // Skip self-cycles
            int j = i;
            int current_val = i;  // Start of the cycle
            while (nums[j] != i) {  // Follow the cycle
                int next_j = nums[j];
                nums[j] = nums[nums[j]];  // Update in-place
                j = next_j;
            }
            nums[j] = nums[current_val];  // Close the cycle
        }
        return nums;
    }
};