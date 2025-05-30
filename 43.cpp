class Solution {
    public:
        string multiply(string num1, string num2) {
            if (num1 == "0" || num2 == "0") return "0";
    
            int n = num1.size();
            int m = num2.size();
            vector<int> result(n + m, 0); // maximum possible length = n + m
    
            for (int i = n - 1; i >= 0; --i) {
                for (int j = m - 1; j >= 0; --j) {
                    int mul = (num1[i] - '0') * (num2[j] - '0');
                    int sum = mul + result[i + j + 1];
    
                    result[i + j + 1] = sum % 10;           // current digit
                    result[i + j] += sum / 10;              // carry to previous digit
                }
            }
    
            // build the final string
            string ans;
            for (int num : result) {
                if (!(ans.empty() && num == 0)) { // skip leading zeros
                    ans.push_back(num + '0');
                }
            }
            return ans.empty() ? "0" : ans;
        }
    };
    