class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int l = 0;
        int big = *max_element(nums.begin(), nums.end());
        long long sum = 0;
        int n = nums.size();
        int count = 0;
        //0 1 2 3 4
        for(int i = 0 ; i < n;i++){
            if(nums[i] == big) count++;
            while(count == k){
                sum += (n - i);
                if(nums[l++] == big) count--;
            }
        }
        return sum;
    }
};