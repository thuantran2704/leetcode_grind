class Solution {
public:
    int helper(vector<int>& bloomDay,int k,int mid){
        int count = 0;
        int n = bloomDay.size();
        int cur = 0;
        for(int i = 0; i < n;i++){
            if(bloomDay[i] <= mid){
                count++;
            } else {
                count = 0;
            }
            if(count == k){
                cur++;
                count = 0;
            }
        }
        return cur;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(m > n/k) return -1;
        int l = *min_element(bloomDay.begin(),bloomDay.end()); 
        int r = *max_element(bloomDay.begin(),bloomDay.end());
        while(l < r){
            int mid = l + (r - l)/2;
            int ans = helper(bloomDay, k,mid);
            if(ans >= m){
                r = mid;
            } else {
                l = mid+1;
            }
        }
        return l;
    }
};