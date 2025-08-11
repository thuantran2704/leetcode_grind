class Solution {
    public:
        vector<int> constructDistancedSequence(int n) {
            vector<int> ans(2 * n - 1, 0);
            vector<bool> used(n + 1, false);
            backtrack(ans, used, n, 0);
            return ans;
        }
    
        bool backtrack(vector<int>& ans, vector<bool>& used, int n, int idx) {
            if (idx == ans.size()) return true;
            if (ans[idx] != 0) return backtrack(ans, used, n, idx + 1);
    
            for (int num = n; num >= 1; num--) {
                if (used[num]) continue;
                if (num == 1) {
                    ans[idx] = 1;
                    used[1] = true;
                    if (backtrack(ans, used, n, idx + 1)) return true;
                    ans[idx] = 0;
                    used[1] = false;
                } else {
                    int j = idx + num;
                    if (j < ans.size() && ans[j] == 0) {
                        ans[idx] = ans[j] = num;
                        used[num] = true;
                        if (backtrack(ans, used, n, idx + 1)) return true;
                        ans[idx] = ans[j] = 0;
                        used[num] = false;
                    }
                }
            }
            return false;
        }
    };
    