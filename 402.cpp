#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string result;
        int keep = num.size() - k;  // The final length of the number
        
        for (char digit : num) {
            // Maintain a monotonically increasing sequence
            while (!result.empty() && k > 0 && result.back() > digit) {
                result.pop_back();
                k--;
            }
            result.push_back(digit);
        }

        // If k is still greater than 0, remove remaining digits from the back
        result.resize(keep);

        // Remove leading zeros
        int start = 0;
        while (start < result.size() && result[start] == '0') {
            start++;
        }

        result = result.substr(start);
        return result.empty() ? "0" : result;
    }
};

// Driver code
int main() {
    Solution sol;
    cout << sol.removeKdigits("1432219", 3) << endl;  // Output: "1219"
    cout << sol.removeKdigits("10200", 1) << endl;    // Output: "200"
    cout << sol.removeKdigits("10", 2) << endl;       // Output: "0"
}
