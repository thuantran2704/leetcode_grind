class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) return true;
            
            // If we cannot determine which half is sorted
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            }
            // Right half is sorted
            else if (nums[mid] < nums[right] || nums[mid] < nums[left]) {
                if (target > nums[mid] && target <= nums[right]) 
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            // Left half is sorted
            else if (nums[mid] > nums[left] || nums[mid] > nums[right]) {
                if (target >= nums[left] && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        
        return false;
    }
};
//standard approach O(n + log n) time complexity

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) return true;
            
            // If we cannot determine which half is sorted
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            }
            // Right half is sorted
            else if (nums[mid] < nums[right] || nums[mid] < nums[left]) {
                if (target > nums[mid] && target <= nums[right]) 
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            // Left half is sorted
            else if (nums[mid] > nums[left] || nums[mid] > nums[right]) {
                if (target >= nums[left] && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        
        return false;
    }
};

//the I tried to be smart ass O(log n) but didn't worked approach that was 262/281 test cases