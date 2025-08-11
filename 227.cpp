class Solution {
    public:
        int calculate(string s) {
            deque<int> dq;
            int n = s.size();
            long num = 0;
            char prev = '+';
            
            for (int i = 0; i < n; i++) {
                char c = s[i];
                if (isdigit(c)) {
                    num = num * 10 + (c - '0');
                }
                
                // If current char is operator or last char in string
                if ((!isdigit(c) && c != ' ') || i == n - 1) {
                    if (prev == '+') {
                        dq.push_back(num);
                    } else if (prev == '-') {
                        dq.push_back(-num);
                    } else if (prev == '*') {
                        int temp = dq.back() * num;
                        dq.pop_back();
                        dq.push_back(temp);
                    } else if (prev == '/') {
                        int temp = dq.back() / num;
                        dq.pop_back();
                        dq.push_back(temp);
                    }
                    prev = c;
                    num = 0;
                }
            }
            
            int result = 0;
            while (!dq.empty()) {
                result += dq.front();
                dq.pop_front();
            }
            return result;
        }
    };