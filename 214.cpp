
class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) return s;

        long long hash_prefix = 0, hash_suffix = 0, power = 1;
        const long long base = 26;
        const long long mod = 1e9 + 7;
        int max_len = 0;

        for (int i = 0; i < s.size(); ++i) {
            hash_prefix = (hash_prefix * base + s[i]) % mod;
            hash_suffix = (hash_suffix + s[i] * power) % mod;

            if (hash_prefix == hash_suffix) {
                max_len = i + 1; // longest palindromic prefix
            }
            power = (power * base) % mod;
        }

        string to_add = s.substr(max_len);
        reverse(to_add.begin(), to_add.end());
        return to_add + s;
    }
};