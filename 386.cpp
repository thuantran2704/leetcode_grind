class Solution {
public:
    void lex(int n, int prev, vector<int>& ans){
        int s = prev == 0 ? 1 : 0;
        for(int i = s ; i <=9;i++){
            int temp = prev*10 + i;
            if(temp > n) break;
            ans.push_back(temp);
            lex(n,temp,ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        lex(n,0,ans);
        return ans;
    }
};