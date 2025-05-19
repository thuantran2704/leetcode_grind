class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& ta, vector<int>& tb){
            if(ta[0] == tb[0]){
                return ta[1] > tb[1];
            } else {
                return ta[0] < tb[0];
            }
        });
        vector<int> dp;
for (auto& env : envelopes) {
    int h = env[1];
    auto it = lower_bound(dp.begin(), dp.end(), h);
    if (it == dp.end()) dp.push_back(h);
    else *it = h;
}
return dp.size(); // max envelopes

    }
};