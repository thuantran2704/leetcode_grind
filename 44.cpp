class Solution {
    public:
        bool helper(string& s, string& p, int i, int j, vector<vector<int>>& match){
            int n1 = s.size();
            int n2 = p.size();
            //first out of bounds.
            if (i == n1 && j == n2) return true;
    
            if (i == n1) {
                while (j < n2 && p[j] == '*') j++;
                return j == n2;
            }
    
            if (j == n2) {
                while (i < n1 && s[i] == '*') i++;
                return i == n1;
            }
            if (match[i][j] != -1) return match[i][j];
            /*
                theres alpha alpha
                ? - alpha
                ? - ?
                * - ?
                * - alpha
                * - * do we keep spiralling till the end or what.
            */
            match[i][j] = 0;
            if(s[i] == '*' || p[j] == '*'){
                match[i][j] = helper(s,p,i+1,j,match) || 
                            helper(s,p,i,j+1,match) || 
                            helper(s,p,i+1,j+1,match);
            } else if((s[i] == '?' || p[j] == '?') || (s[i] == p[j])){
                match[i][j] = helper(s,p,i+1,j+1,match);
            }
            return match[i][j];
        }
        bool isMatch(string s, string p) {
            int n1 = s.size();
            int n2 = p.size();
            vector<vector<int>> match(n1+1,vector<int>(n2+1,-1));
            
            return helper(s,p,0,0, match);
        }
    };