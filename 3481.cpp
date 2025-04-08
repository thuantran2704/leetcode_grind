class Solution {
    public:
        // Expand a single key recursively using memoization
        string expand(string key, unordered_map<string, string>& rep, unordered_map<string, string>& memo) {
            if (memo.count(key)) return memo[key];
            string &val = rep[key];
            string result = "";
    
            for (int i = 0; i < val.size(); ) {
                if (val[i] == '%') {
                    int j = i + 1;
                    string inner = "";
                    while (j < val.size() && val[j] != '%') inner += val[j++];
                    if (j < val.size()) {
                        result += expand(inner, rep, memo);
                        i = j + 1;
                    } else {
                        result += val[i++];
                    }
                } else {
                    result += val[i++];
                }
            }
    
            return memo[key] = result;
        }
    
        // Replaces a placeholder %x% in text with val
        string replace(string &temp, int i, string &r){
            int n = temp.size();
            string start = temp.substr(0, i);
            string end = (i + 3 <= n) ? temp.substr(i + 3) : "";
            return start + r + end;
        }
    
        string applySubstitutions(vector<vector<string>>& replacements, string text) {
            unordered_map<string, string> rep;
            unordered_map<string, string> memo;
    
            for (auto &r : replacements) {
                rep[r[0]] = r[1];
            }
    
            // Expand each key once and cache
            for (auto &[key, _] : rep) {
                expand(key, rep, memo);
            }
    
            // Replace placeholders in text
            for (int t = 0; t < text.size(); ) {
                if (text[t] == '%') {
                    int k = t + 1;
                    string key = "";
                    while (k < text.size() && text[k] != '%') key += text[k++];
                    if (k < text.size() && memo.count(key)) {
                        text = replace(text, t, memo[key]);
                        t = -1; // restart after string mutation
                    }
                }
                t++;
            }
    
            return text;
        }
    };