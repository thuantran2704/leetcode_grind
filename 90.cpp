class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allset = {{}};
        int startIdx = 0, endIdx = 0;

        for (int i = 0; i < nums.size(); ++i) {
            startIdx = 0;

            // If current is same as previous, only extend the subsets 
            // added in the previous round to avoid duplicates
            if (i > 0 && nums[i] == nums[i - 1]) {
                startIdx = endIdx + 1;
            }

            endIdx = allset.size() - 1;
            int currentSize = allset.size();

            for (int j = startIdx; j < currentSize; ++j) {
                vector<int> temp = allset[j];
                temp.push_back(nums[i]);
                allset.push_back(temp);
            }
        }

        return allset;
    }
};
