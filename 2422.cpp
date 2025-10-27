class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int count = 0;
        int mod = 1e9+7;
        while(l < r){
            if(nums[l] == nums[r]){
                l++;
                r--;
            } else if(nums[l] < nums[r]){
                l++;
                nums[l] += nums[l-1];
                nums[l] %= mod;
                count++;
            } else if(nums[l] > nums[r]){
                r--;
                nums[r] += nums[r+1];
                nums[r] %= mod;
                count++;
            }
        }
        return count;
    }
};