class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums.back() - nums.front();

        for (int i = 0; i < n - 1; ++i) {
            int high = max(nums.back() - k, nums[i] + k);
            int low = min(nums.front() + k, nums[i + 1] - k);
            ans = min(ans, high - low);
        }

        return ans;
    }
};
