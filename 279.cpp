class Solution {
public:
    int numSquares(int n) {
        vector<int> nums;
        for(int i = 1 ; i * i <= n;i++){
            nums.push_back(i * i);
        }
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(auto& num: nums){
            for(int i = num; i <= n; i++){
                if(dp[i - num] == INT_MAX) continue;
                dp[i] = min(dp[i-num] + 1, dp[i]);
            }
        }
        return dp[n];
    }
};