class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            if (nums.empty()) return {};
    
            // Sort the numbers in ascending order
            sort(nums.begin(), nums.end());
    
            int n = nums.size();
            vector<int> dp(n, 1);  // dp[i] will store the size of the largest subset ending at nums[i]
            vector<int> prev(n, -1);  // prev[i] will store the index of the previous element in the subset
            
            int max_size = 1;
            int max_index = 0;
    
            // DP to build up the largest divisible subset
            for (int i = 1; i < n; ++i) {
                for (int j = 0; j < i; ++j) {
                    if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
                if (dp[i] > max_size) {
                    max_size = dp[i];
                    max_index = i;
                }
            }
    
            // Backtrack to construct the largest divisible subset
            vector<int> result;
            while (max_index != -1) {
                result.push_back(nums[max_index]);
                max_index = prev[max_index];
            }
    
            // Reverse the result to get the correct order
            reverse(result.begin(), result.end());
    
            return result;
        }
    };

    