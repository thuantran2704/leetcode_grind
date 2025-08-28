class Solution {
public:
    void dfs(vector<vector<int>>& ans, int n, int k, vector<int>& cur, int num){
        if(cur.size() == k){
            ans.push_back(cur);
            return;
        }
        for(int i = num; i <= n;i++){
            if(k - cur.size() > n - i +1) break;
            //end early if not enough space left.
            cur.push_back(i);
            dfs(ans, n,k,cur,i+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(ans, n, k, cur, 1);
        return ans;
    }
};