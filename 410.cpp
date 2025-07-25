class Solution {
    public:
        int splitArray(vector<int>& nums, int k) {
            int n = nums.size();
            int left = 0, right = 0;
    
            // left is max element, right is sum of all elements
            for (auto& num : nums) {
                left = max(left, num);
                right += num;
            }
    
            // binary search for smallest max subarray sum
            while (left < right) {
                int mid = left + (right - left) / 2;
                int idx = 0;
                int parts = 0;
    
                while (parts < k && idx < n) {
                    int sum = 0;
                    while (idx < n && sum + nums[idx] <= mid) {
                        sum += nums[idx++];
                    }
                    parts++;
                }
    
                if (idx == n) {
                    // mid is a valid max sum, try smaller
                    right = mid;
                } else {
                    // mid too small, try bigger
                    left = mid + 1;
                }
            }
    
            return left;  // left == right, smallest max sum found
        }
    };
    