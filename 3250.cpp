class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[2001][52]; // Only memoize index and prevX1
//somehow better than 89% of leetcode solutions man
    // Recursive DP with memoization over i and prevX1 only
    int countWays(int i, int n, const vector<int>& nums, int prevX1, int prevX2) {
        if (i == n) return 1;

        if (dp[i][prevX1] != -1)
            return dp[i][prevX1];

        int ways = 0;
        int total = nums[i];

        for (int x1 = prevX1; x1 <= total; ++x1) {
            int x2 = total - x1;

            if (x2 <= prevX2) {
                ways = (ways + countWays(i + 1, n, nums, x1, x2)) % MOD;
            }
        }

        return dp[i][prevX1] = ways;
    }

    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return countWays(0, n, nums, 0, 50); // Start with lowest x1 and highest x2 allowed
    }
};

