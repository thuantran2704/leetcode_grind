class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        int n = strs.size();
        for(int i = 0 ;i < n;i++){
            string temp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            map[strs[i]].push_back(temp);
        }
        vector<vector<string>> ans;
        for (auto& p: map){
            ans.push_back(p.second);
        }
        return ans;
    }
};