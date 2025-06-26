class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans(1,vector<int>(n, -11));
        for(int i = n-1; i >= 0; i--){
            //i is now both empty spot left -1 and the index of the current num in nums
            int k = ans.size();
            for(int j = 0 ;j < k; j++){
                //now it's going through all the available ones.
                int t = i+1;
                for(int idx = 0; idx < n && t > 0;idx++){
                    if(ans[j][idx] != -11) continue;
                    if(t == 1){
                        ans[j][idx] = nums[i];
                    } else {
                        vector<int> temp = ans[j];
                        temp[idx] = nums[i];
                        ans.push_back(temp);
                    }
                    t--;
                }
            }
        }
        return ans;
    }
};