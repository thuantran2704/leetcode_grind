class Solution {
    public:
        int validSubarrays(vector<int>& nums) {
            stack<int> st;
            int count = 0;
            nums.push_back(-1);
    
            int n = nums.size();
            for(int i = 0 ; i < n;i++){
                while(!st.empty() && nums[st.top()] > nums[i]){
                    int pi = st.top();
                    st.pop();
                    //process it.
                    count += (i - pi);
                }
    
                st.push(i);
            }
            return count;
        }
    };