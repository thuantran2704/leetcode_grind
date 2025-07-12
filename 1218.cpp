class Solution {
    public:
        int longestSubsequence(vector<int>& arr, int difference) {
            unordered_map<int,int> prev;
            int n = arr.size();
            int maxans = 1;
            for(int i = 0 ; i < n;i++){
                int previous = arr[i] - difference;
                if(prev.find(previous) != prev.end()){
                    prev[arr[i]] = prev[previous] + 1;
                    maxans = max(prev[arr[i]], maxans);
                } else {
                    prev[arr[i]] = 1;
                }
            }
            return maxans;
        }
    };