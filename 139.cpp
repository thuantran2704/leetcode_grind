class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        deque<int> sidx;
        sidx.push_back(0);
        
        unordered_set<int> visited;
        visited.insert(0);
        auto it = *max_element(wordDict.begin(), wordDict.end(), [&](string a, string b) -> bool {
            return a.size() < b.size();
        });
        
        int k = it.size();
        for(int i = 0 ; i < n;i++){
            while(!sidx.empty() && i - sidx.front() + 1 > k) sidx.pop_front();
            for(auto p: sidx){
                if(dict.count(s.substr(p, i - p + 1))){
                    if(i == n-1) return true;
                    sidx.push_back(i+1);

                    break;
                }
            }
            
        }
        return false;
    }
};