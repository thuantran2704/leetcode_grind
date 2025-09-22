class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        vector<bool> dp(sum/2+1, false);
        dp[0] = true;
        for(auto& stone: stones){
            for(int i = sum/2; i >= stone;i--){
                dp[i] = dp[i] || dp[i-stone];
            }
        }
        for(int i = sum/2;i >= 0; i--){
            if(dp[i]) return (sum - 2*i);
        }
        return 0;
    }
};