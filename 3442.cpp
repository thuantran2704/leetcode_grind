class Solution {
public:
    int maxDifference(string s) {
        int mae = INT_MIN, mie = INT_MAX;
        int mao = INT_MIN, mio = INT_MAX;
        unordered_map<char, int> freq;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            freq[s[i]]++;
        }

        for (auto& p : freq) {
            if (p.second % 2 == 0) {
                mae = max(mae, p.second);
                mie = min(mie, p.second);
            } else {
                mao = max(mao, p.second);
                mio = min(mio, p.second);
            }
        }

        int res = INT_MIN;
        if (mao != INT_MIN && mie != INT_MAX) {
            res = max(res, mao - mie);
        }
        if (mio != INT_MAX && mae != INT_MIN) {
            res = max(res, mio - mae);
        }

        return res == INT_MIN ? 0 : res;
    }
};
