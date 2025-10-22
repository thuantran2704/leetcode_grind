class Solution {
public:
    long findID(long x, long width) {
        return x >= 0 ? x / width : ((x + 1) / width) - 1;
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if (valueDiff < 0) return false;
        unordered_map<long, long> bucket;
        long width = (long)valueDiff + 1; // bucket size

        for (int i = 0; i < nums.size(); i++) {
            long num = nums[i];
            long id = findID(num, width);

            // same bucket
            if (bucket.count(id)) return true;

            // adjacent buckets
            if (bucket.count(id - 1) && abs(num - bucket[id - 1]) <= valueDiff) return true;
            if (bucket.count(id + 1) && abs(num - bucket[id + 1]) <= valueDiff) return true;

            // insert into bucket
            bucket[id] = num;

            // remove element out of sliding window
            if (i >= indexDiff) {
                long oldId = findID(nums[i - indexDiff], width);
                bucket.erase(oldId);
            }
        }

        return false;
    }
};
