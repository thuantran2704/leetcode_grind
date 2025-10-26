class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int smallest = *min_element(nums.begin(), nums.end());
        int biggest = *max_element(nums.begin(), nums.end());
        return max(biggest - smallest - 2* k, 0);
    }
};