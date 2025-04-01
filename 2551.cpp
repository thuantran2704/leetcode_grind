#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        long long base = weights[0] + weights[n - 1];
        vector<long long> cutCosts;
        for (int i = 0; i < n - 1; i++) {
            cutCosts.push_back(weights[i] + weights[i + 1]);
        }
        sort(cutCosts.begin(), cutCosts.end());
        long long minScore = base;
        for (int i = 0; i < k - 1; i++) {
            minScore += cutCosts[i];
        }
        long long maxScore = base;
        for (int i = 0; i < k - 1; i++) {
            maxScore += cutCosts[cutCosts.size() - 1 - i];
        }
        return maxScore - minScore;
    }
};

void runTests() {
    Solution sol;
    
    vector<int> weights1 = {1, 3, 5, 1};
    assert(sol.putMarbles(weights1, 2) == 4);
    
    vector<int> weights2 = {1, 3};
    assert(sol.putMarbles(weights2, 2) == 0);
    
    vector<int> weights3 = {5, 1, 2, 6, 3};
    assert(sol.putMarbles(weights3, 3) == 7);
    
    vector<int> weights4 = {4, 2, 7, 6, 9, 3};
    assert(sol.putMarbles(weights4, 4) == 10);
    
    vector<int> weights5 = {10, 20, 30, 40, 50};
    assert(sol.putMarbles(weights5, 3) == 30);
    
    cout << "All test cases passed!" << endl;
}

int main() {
    runTests();
    return 0;
}
