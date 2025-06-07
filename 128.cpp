class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int c = 0;
        for(int num: s){
            if(s.count(num-1)) continue;
            int start = num;
            while(s.count(start)) start++;
            c = max(start - num, c);
        }
        return c;
    }
};