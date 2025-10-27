class Solution {
public:
    int minArrayLength(vector<int>& nums, int k) {
        vector<long long> st;
        for (int x : nums) {
            long long val = x;
            while (!st.empty() && st.back() * val <= k) {
                val = st.back() * val;
                st.pop_back();
            }
            st.push_back(val);
        }
        return st.size();
    }
};
