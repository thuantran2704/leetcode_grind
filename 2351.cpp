class Solution {
    public:
        char repeatedCharacter(string s) {
            unordered_set<char> met;
            int n = s.size();
            for(int i = 0 ; i < n;i++){
                if(met.count(s[i])) return s[i];
                else met.insert(s[i]);
            }
            return '.';
        }
    };