#define MOD 1000000007
class Solution {
public:
    int choose2(int n){
        if (n < 2) return 0;
        long long temp = (long long) n * (n - 1) / 2;
        temp %= MOD;
        return (int) temp;
    }
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int> lines;
        for(auto& point: points){
            ++lines[point[1]];
        }
        
        unordered_map<int,int> linePairs;
        int sumPairs = 0;
        for(auto& p: lines){
            int c2 = choose2(p.second);
            linePairs[p.first] = c2;
            sumPairs = (sumPairs + c2) % MOD;
        }
        
        int ans = 0;
        for(auto& p: linePairs){
            int otherPairs = sumPairs - p.second;
            if(otherPairs < 0) otherPairs += MOD;
            ans = (ans + (long long)p.second * otherPairs) % MOD;
        }
        const int inv2 = 500000004;
        ans = (int)((long long)ans * inv2 % MOD);
        
        return ans;
    }
};