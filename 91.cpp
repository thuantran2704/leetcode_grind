class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(s[0] == '0') return 0;
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n;i++){
            if(s[i-1] != '0') dp[i] += dp[i-1];
            int temp = (s[i-2] - '0') * 10 + (s[i-1] - '0');
            if( temp < 27 && temp >=10) dp[i] += dp[i-2];
        }
        return dp[n];
    }
};