class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        int count = 0;
        int lastInvalid = -1;
        int lastValid = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] > right)
                lastInvalid = i;  // cannot include this element
            if (nums[i] >= left && nums[i] <= right)
                lastValid = i;    // update latest valid index
            if (lastValid != -1)
                count += max(0, lastValid - lastInvalid);
        }

        return count;
    }
};