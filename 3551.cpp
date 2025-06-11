class Solution {
public:
    int digitSum(int n) {
        int ans = 0;
        while (n > 0) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        // 1️⃣ Group by digit sum
        map<int, vector<int>> m;
        for (int i = 0; i < n; ++i) {
            int sum = digitSum(nums[i]);
            m[sum].push_back(nums[i]);
        }
        
        // 2️⃣ Sort each group
        vector<int> target;
        for (auto& p : m) {
            sort(p.second.begin(), p.second.end());
            target.insert(target.end(), p.second.begin(), p.second.end());
        }

        // 3️⃣ Map value to its final position
        unordered_map<int, vector<int>> valToIdx;
        for (int i = 0; i < n; ++i) {
            valToIdx[target[i]].push_back(i);
        }

        // 4️⃣ Directly swap to final positions
        int swaps = 0;
        for (int i = 0; i < n; ++i) {
            while (nums[i] != target[i]) {
                int val = nums[i];
                int finalIdx = valToIdx[val].back();
                valToIdx[val].pop_back();

                // Swap directly
                swap(nums[i], nums[finalIdx]);
                ++swaps;
            }
        }
        
        return swaps;
    }
};
