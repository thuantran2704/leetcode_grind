class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            if (nums.empty()) return 0;
    
            unordered_set<int> map;
            map.reserve(nums.size());
            for (int num : nums) {
                map.insert(num);
            }
    
            int maxLen = 0;
    
            for (int num : nums) {
                if (!map.count(num)) continue; // already visited via earlier sequence
    
                map.erase(num);
                int currLen = 1;
    
                int left = num - 1;
                while (map.erase(left)) {
                    left--;
                    currLen++;
                }
    
                int right = num + 1;
                while (map.erase(right)) {
                    right++;
                    currLen++;
                }
    
                maxLen = max(maxLen, currLen);
            }
    
            return maxLen;
        }
    };
    