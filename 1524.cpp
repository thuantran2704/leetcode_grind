class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int count_odd = 0;
        int count_even = 1;
        int total = 0;
        int n = arr.size();
        int MOD = 1e9 + 7;
        int cur_sum = 0;
        for(int i = 0 ; i  < n;i++){
            cur_sum += arr[i];
            if(cur_sum %2 == 0){
                count_even++;
                total =(total + count_odd) % MOD;
            } else {
                count_odd++;
                total =(total + count_even ) % MOD;
            }
        }
        return total;
    }
};