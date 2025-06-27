//time wise efficient but is 3 dimensional storage wise
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<vector<string>>> ans(n);
        auto explore = [&](int i, int j){
            while(i >= 0 && j < n && s[i] == s[j]){
                vector<vector<string>> prev = i > 0 ? ans[i-1] : vector<vector<string>>{{}};
                string cur = s.substr(i, j - i + 1);
                int k = prev.size();
                for(int t = 0; t < k;t++){
                    prev[t].push_back(cur);
                    ans[j].push_back(prev[t]);
                }
                i--;
                j++;
            }
        };
        for(int i = 0 ; i < n;i++){
            explore(i,i);
            explore(i,i+1);
        }
        return ans[n-1];
    }
};

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // Initialize the DP table for single characters and pairs
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        for (int length = 2; length <= n; ++length) {
            for (int i = 0; i <= n - length; ++i) {
                int j = i + length - 1;
                if (s[i] == s[j] && (length == 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                }
            }
        }

        vector<vector<string>> result;
        vector<string> path;
        backtrack(s, 0, path, result, dp);
        return result;
    }

private:
    void backtrack(const string& s, int start, vector<string>& path, vector<vector<string>>& result, const vector<vector<bool>>& dp) {
        // If we've reached the end of the string, add the current partition to the result list
        if (start == s.length()) {
            result.push_back(path);
            return;
        }
        // Explore all possible partitions
        for (int end = start; end < s.length(); ++end) {
            // Use the DP table to check if the substring s[start:end+1] is a palindrome
            if (dp[start][end]) {
                path.push_back(s.substr(start, end - start + 1));
                // Recur to find other partitions
                backtrack(s, end + 1, path, result, dp);
                // Backtrack to explore other partitions
                path.pop_back();
            }
        }
    }
};
// This solution uses a dynamic programming approach to find all palindromic partitions of a string.
// It builds a DP table to check if substrings are palindromes and uses backtracking