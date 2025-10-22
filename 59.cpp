class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left = 0;
        int right = n-1;
        int up = 0;
        int down = n-1;
        int cur = 1;
        vector<vector<int>> ans(n, vector<int>(n,0));
        while(left <= right && up <= down){
            int j = left;
            while(j <= right){
                ans[up][j++] = cur;
                cur++;
            }
            up++;
            int i = up;
            while(i <= down){
                ans[i++][right] = cur;
                cur++;
            }
            right--;
            j = right;
            while(j>= left){
                ans[down][j--] = cur;
                cur++;
            }
            down--;
            i = down;
            while(i >= up){
                ans[i--][left] = cur;
                cur++;
            }
            left++;
        }
        return ans;
    }
};