class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> target(26, 0), window(26, 0);
        for (char c : s1) target[c - 'a']++;

        int n1 = s1.size();
        for (int i = 0; i < s2.size(); ++i) {
            window[s2[i] - 'a']++;

            // Keep window size == n1
            if (i >= n1)
                window[s2[i - n1] - 'a']--;

            if (window == target)
                return true;
        }
        return false;
    }
};

