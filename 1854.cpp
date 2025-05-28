class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int ans = 0;
        vector<int> years(101,0);
        int n = logs.size();
        for(int i = 0 ; i < n;i++){
            int s = logs[i][0] - 1950;
            int e = logs[i][1] - 1950;
            years[s]++;
            years[e]--;
        }
        int cur = 0;
        int year = 0;
        for(int i = 0 ; i < 101;i++){
            cur += years[i];
            if(cur > ans){
                ans = cur;
                year = i;
            }
        }
        return year + 1950;
    }
};