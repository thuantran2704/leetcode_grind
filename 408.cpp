class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int n = word.size();
        int m = abbr.size();
        int i = 0, j = 0;

        while (j < m) {
            if (isdigit(abbr[j])) {
                if (abbr[j] == '0') return false; // no leading zero

                int t = 0;
                while (j < m && isdigit(abbr[j])) {
                    t = t * 10 + (abbr[j] - '0');
                    j++;
                }

                i += t; // skip t letters
                if (i > n) return false; // can't skip past word's length
            } else {
                if (i >= n || abbr[j] != word[i]) return false;
                i++;
                j++;
            }
        }

        return i == n; // ensure no extra letters in word
    }
};
