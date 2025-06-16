class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        int mia = INT_MAX;
        int k = t.size();
        int n = s.size();
        int best_start = 0;
        unordered_map<char,int> map;
        if(k > n) return "";
        unordered_map<char,int> need;
        int req = 0;
        for(int i = 0; i < k;i++){
            map[t[i]] ++;
        }
        req = map.size();

        int i = 0;
        int start = 0;
        while(i < n){
            if(map.find(s[i]) != map.end()){
                need[s[i]]++;
                if(need[s[i]] == map[s[i]]){
                    req--;
                }
                //make sures to update first.
            }

            while(start <= i && req == 0){
                int dist = i - start + 1;
                if(mia > dist){
                    mia = dist;
                    best_start = start;
                }
                //removes shit.
                if(map.find(s[start]) != map.end()){
                    if(need[s[start]] == map[s[start]]){
                        req++;
                    }
                    need[s[start]]--;
                    //make sures to update first.
                }
                start++;
            }
            i++;
        }
        return mia == INT_MAX ? "" : s.substr(best_start, mia);
    }
};