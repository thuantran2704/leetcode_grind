class Solution {
    public:
        vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
            int n = mat.size();
            int m = mat[0].size();
            vector<int> ans;
            ans.reserve(n * m);
    
            int i = 0, j = 0;
            bool up = true;
    
            for (int k = 0; k < n * m; k++) {
                ans.push_back(mat[i][j]);
    
                if (up) { // moving up-right
                    if (j == m - 1) { // right edge
                        i++;
                        up = false;
                    } else if (i == 0) { // top edge
                        j++;
                        up = false;
                    } else {
                        i--;
                        j++;
                    }
                } else { // moving down-left
                    if (i == n - 1) { // bottom edge
                        j++;
                        up = true;
                    } else if (j == 0) { // left edge
                        i++;
                        up = true;
                    } else {
                        i++;
                        j--;
                    }
                }
            }
            return ans;
        }
    };
    