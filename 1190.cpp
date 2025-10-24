class Solution {
public:
    pair<string,int> reverseStr(string& s, int idx){
        //idx is expected to be start of the sequence - not '('
        string temp = "";
        int n = s.size();
        while(idx < n && s[idx] != ')'){
            if(s[idx] == '('){ 
                pair<string,int> tmp = reverseStr(s, idx + 1);
                idx = tmp.second;
                temp += tmp.first;
            } else temp += s[idx++];
        }
        reverse(temp.begin(), temp.end());
        return {temp, idx+1};
    }
    //should return reversed part + ending index (after the ')')
    string reverseParentheses(string s) {
        pair<string,int> ans = reverseStr(s, 0);
        reverse(ans.first.begin(), ans.first.end());
        return ans.first;

    }
};