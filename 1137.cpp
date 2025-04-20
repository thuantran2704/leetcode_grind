class Solution {
    public:
        unordered_map<int, int> val;
    
        int tribonacci(int n) {
            if (n == 0) return 0;
            if (n == 1 || n == 2) return 1;
    
            if (val.find(n) != val.end()) return val[n];
    
            val[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
            return val[n];
        }
    };
    