class Solution {
    public:
        int peopleAwareOfSecret(int n, int delay, int forget) {
            const int MOD = 1e9 + 7;
            vector<long> dp(n + 1, 0);  // dp[i] = #people who learn on day i
            dp[1] = 1;
    
            long total = 1;  // total active people who can share
    
            for (int day = 2; day <= n; day++) {
                dp[day] = 0;
    
                // Add people who can share today
                for (int j = max(1, day - forget + 1); j <= day - delay; j++) {
                    dp[day] = (dp[day] + dp[j]) % MOD;
                }
    
                total = (total + dp[day]) % MOD;
            }
    
            // Count people who still know secret at day n
            long ans = 0;
            for (int day = n - forget + 1; day <= n; day++) {
                if (day >= 1)
                    ans = (ans + dp[day]) % MOD;
            }
    
            return ans;
        }
    };
    