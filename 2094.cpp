class Solution {
    public:
        vector<int> ans;
    
        void bt(vector<int>& digits, vector<bool>& used, int cur, int depth) {
            if (depth == 3) {
                if (cur % 2 == 0)
                    ans.push_back(cur);
                return;
            }
    
            for (int i = 0; i < digits.size(); ++i) {
                if (used[i]) continue;
                // Skip leading zero
                if (depth == 0 && digits[i] == 0) continue;
                // Avoid duplicates at same depth
                if (i > 0 && digits[i] == digits[i - 1] && !used[i - 1]) continue;
    
                used[i] = true;
                bt(digits, used, cur * 10 + digits[i], depth + 1);
                used[i] = false;
            }
        }
    
        vector<int> findEvenNumbers(vector<int>& digits) {
            sort(digits.begin(), digits.end()); // handle duplicates correctly
            vector<bool> used(digits.size(), false);
            bt(digits, used, 0, 0);
    
            sort(ans.begin(), ans.end());
            ans.erase(unique(ans.begin(), ans.end()), ans.end()); // remove duplicates
    
            return ans;
        }
    };
    