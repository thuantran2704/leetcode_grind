class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int cur = 2;
        int ans = 0;
        if(n == 1) return 0;
        int dif = nums[1] - nums[0];
        for(int i = 2 ; i < n;i++){
            if(nums[i]- nums[i-1] == dif){
                cur++;
                if(cur >= 3){
                    ans += (cur - 2);
                }
            } else {
                dif = nums[i] - nums[i-1];
                cur = 2;
            }
        }
        return ans;
    }
};