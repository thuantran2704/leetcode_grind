class Solution {
public:
    const double EPS = 1e-6;

    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }

private:
    bool solve(vector<double> nums) {
        if (nums.size() == 1) {
            return fabs(nums[0] - 24.0) < EPS;
        }

        // Try all pairs
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) continue;

                vector<double> next;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j) next.push_back(nums[k]);
                }

                double a = nums[i], b = nums[j];

                // + and * are commutative, so only try when i < j
                if (i < j) {
                    next.push_back(a + b);
                    if (solve(next)) return true;
                    next.pop_back();

                    next.push_back(a * b);
                    if (solve(next)) return true;
                    next.pop_back();
                }

                // subtraction
                next.push_back(a - b);
                if (solve(next)) return true;
                next.pop_back();

                // division
                if (fabs(b) > EPS) {
                    next.push_back(a / b);
                    if (solve(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }
};
