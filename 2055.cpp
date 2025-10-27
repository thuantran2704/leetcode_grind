class Solution {
public:
    int check(vector<int>& query, string& s, vector<pair<int,int>>& candles, vector<int>& prefix){
        int start = query[0];
        int end = query[1];
        
        // first candle >= start
        int L = candles[start].second; 
        // last candle <= end
        int R = candles[end].first;  

        if(L != -1 && R != -1 && L < R){
            return prefix[R] - prefix[L]; // plates between candles
        }
        return 0;
    }

    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<pair<int,int>> candles(n, {-1,-1});
        int last = -1;

        // nearest candle to left
        for(int i = 0 ; i < n; i++){
            if(s[i] == '|') last = i;
            candles[i].first = last;
        }

        // nearest candle to right
        last = -1;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '|') last = i;
            candles[i].second = last;
        }

        // prefix sum of plates
        vector<int> prefix(n,0);
        for(int i = 0; i < n; i++)
            prefix[i] = (s[i] == '*' ? 1 : 0) + (i > 0 ? prefix[i-1] : 0);

        vector<int> ans;
        for(auto& q : queries){
            ans.push_back(check(q, s, candles, prefix));
        }
        return ans;
    }
};
