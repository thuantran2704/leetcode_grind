class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        if(arr[0] > arr[1]) return arr[1];
        int n = arr.size();
        if(arr[n-1] > arr[n-2]) return arr[n-1];
        int l = 0;
        int r = n-1;
        while(l < r){
            int mid = l + (r - l)/2;
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
                return mid;
            } else if(arr[mid] > arr[mid-1]){
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
};