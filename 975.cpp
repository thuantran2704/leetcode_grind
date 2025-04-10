class Solution {
    public:
        int oddEvenJumps(vector<int>& arr) {
            int n = arr.size();
            vector<int> nextHigher(n, -1);
            vector<int> nextLower(n, -1);
            
            // Create indices 0 ... n-1.
            vector<int> indices(n);
            iota(indices.begin(), indices.end(), 0);
            
            // Compute nextHigher using a monotonic increasing stack.
            sort(indices.begin(), indices.end(), [&](int i, int j) {
                return arr[i] < arr[j] || (arr[i] == arr[j] && i < j);
            });
            stack<int> st;
            for (int i : indices) {
                while (!st.empty() && i > st.top()) {
                    nextHigher[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
            
            // Compute nextLower using a monotonic decreasing stack.
            sort(indices.begin(), indices.end(), [&](int i, int j) {
                return arr[i] > arr[j] || (arr[i] == arr[j] && i < j);
            });
            while (!st.empty()) st.pop();
            for (int i : indices) {
                while (!st.empty() && i > st.top()) {
                    nextLower[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
            
            // Step 2. DP from rightmost index backwards.
            vector<bool> canReachOdd(n, false), canReachEven(n, false);
            canReachOdd[n-1] = canReachEven[n-1] = true;
            for (int i = n - 2; i >= 0; --i) {
                if (nextHigher[i] != -1)
                    canReachOdd[i] = canReachEven[nextHigher[i]];
                if (nextLower[i] != -1)
                    canReachEven[i] = canReachOdd[nextLower[i]];
            }
            
            // Count the number of indices that can reach the end on an odd jump.
            int result = 0;
            for (bool canJump : canReachOdd)
                if (canJump) result++;
            return result;
        }
    };
    