class Solution {
public:
    void backtrack(vector<string>& ans, string& s, int idx, unordered_set<string>& words, int max_size, string cur){
        if(idx == s.size()){
            ans.push_back(cur);
            return;
        }
        for(int i = 0 ; i < min((int)s.size() - idx, max_size); i++){
            string temp = s.substr(idx, i + 1);
            if(words.count(temp)){
                string maybe = cur.empty() ? temp : cur + ' ' + temp;
                backtrack(ans, s, idx + i + 1, words, max_size, maybe);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        unordered_set<string> dict;
        int max_size = 0;
        for(auto& word: wordDict){
            dict.insert(word);
            max_size = max(max_size, (int)word.size());
        }
        backtrack(ans, s, 0, dict, max_size, "");
        return ans;
    }
};
