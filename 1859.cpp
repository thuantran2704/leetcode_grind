class Solution {
public:
    string sortSentence(string s) {
        int n = s.size();
        vector<string> ans(10,"");
        string cur = "";
        for(int i = 0 ; i < n;i++){
            if(isdigit(s[i])){
                ans[s[i] - '0'] = cur;
                cur = "";
            } else {
                cur += s[i];
            }
        }
        string res = "";
        for(int i = 0 ; i < 10;i++){
            if(ans[i].size() > 0) res += ans[i];
            else break;
        }
        return res;
    }
};