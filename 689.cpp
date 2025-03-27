#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> ksum(n - k + 1, 0), L(n - 3 * k + 1, -1);
        int maxKsum = ksum[0] = accumulate(nums.begin(), nums.begin() + k, 0);
        L[0] = 0;
        for (int i = 1; i < n - k + 1; i++) {
            ksum[i] = ksum[i - 1] - nums[i - 1] + nums[i + k - 1];
            if (i > n - 3 * k) continue;
            if (maxKsum < ksum[i]) {
                maxKsum = ksum[i];
                L[i] = i;
            } else L[i] = L[i - 1];
        }
        vector<int> R(n - 3 * k + 1, -1);
        maxKsum = ksum.back();
        R.back() = n - k;
        for (int i = n - k - 1; i >= 2 * k; i--) {
            if (maxKsum <= ksum[i]) { // multiple answers, return the lexicographically smallest one
                maxKsum = ksum[i];
                R[i - 2 * k] = i;
            } else R[i - 2 * k] = R[i + 1 - 2 * k];
        }
        vector<int> ans(3, -1);
        int max3K = 0;
        for (int i = 0; i <= n - 3 * k; i++) {
            int sum3K = ksum[L[i]] + ksum[i + k] + ksum[R[i]];
            if (sum3K > max3K) {
                max3K = sum3K;
                ans = {L[i], i + k, R[i]};
            }
        }
        return ans;
    }
};

void runTest(vector<int> nums, int k, vector<int> expected, int testNum) {
    Solution sol;
    vector<int> result = sol.maxSumOfThreeSubarrays(nums, k);
    cout << "Test " << testNum << ": ";
    if (result == expected) {
        cout << "PASSED ✅\n";
    } else {
        cout << "FAILED ❌ (Expected: ";
        for (int x : expected) cout << x << " ";
        cout << ", Got: ";
        for (int x : result) cout << x << " ";
        cout << ")\n";
    }
}

int main() {
    // Test cases
    runTest({1,2,1,2,6,7,5,1}, 2, {0, 3, 5}, 1);
    runTest({4,3,2,1,5,6,1,2,3,4}, 3, {0, 4, 7}, 2);
    runTest({1,1,1,1,1,1,1,1,1}, 3, {0, 3, 6}, 3);
    runTest({9,8,7,6,5,4,3,2,1}, 2, {0, 2, 4}, 4);
    runTest({10,20,30,40,50,60,70,80,90,100}, 1, {7, 8, 9}, 5);
    runTest({100,200,300,400,500,600,700,800,900,1000}, 2, {6, 7, 8}, 6);

    return 0;
}
