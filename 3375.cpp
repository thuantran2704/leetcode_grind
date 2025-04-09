class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            unordered_map<int,int> map;
            int n = nums.size();
            map[k] = 1;
            for(int i = 0 ; i < n;i++){
                map[nums[i]]++;
                if(nums[i] < k) return -1;
            }
            //0 1 2 3 4 5
            return map.size()-1;
        }
    };