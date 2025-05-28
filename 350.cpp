class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int,int> freq;
        for(int i = 0 ; i < n;i++){
            freq[nums1[i]]++;
        }
        vector<int> ans;
        for(int i = 0 ; i < m;i++){
            int t = nums2[i];
            if(freq.find(t)!= freq.end() && freq[t] > 0){
                ans.push_back(t);
                freq[t]--;
            }
        }
        return ans;
    }
};