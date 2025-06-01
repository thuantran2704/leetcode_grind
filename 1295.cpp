class Solution {
public:
    bool ised(int n){
        if(n == 0) return false;
        bool ans = true;
        while(n && n/10){
            n /= 100;
        }
        if(n) ans = false;
        return ans;
    }
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0 ; i < n;i++){
            if(ised(nums[i])) count++;
        }
        return count;
    }
};