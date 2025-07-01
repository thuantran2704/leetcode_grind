class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1; // Base case: empty string is a subsequence of any string

        for (char sc : s) {
            // Traverse t from back to front
            for (int j = n - 1; j >= 0; --j) {
                if (sc == t[j]) {
                    dp[j + 1] += dp[j];
                }
            }
        }
        return dp[n];
    }
};
