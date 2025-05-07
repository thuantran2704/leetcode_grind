class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            // rows[i][d] == true means digit d+1 already seen in row i
            bool rows[9][9] = {}, cols[9][9] = {}, boxes[9][9] = {};
    
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    if (board[i][j] == '.') continue;
    
                    int num = board[i][j] - '1';  // Convert '1'-'9' to 0-8
                    int boxIndex = (i / 3) * 3 + (j / 3);
    
                    if (rows[i][num] || cols[j][num] || boxes[boxIndex][num])
                        return false;
    
                    rows[i][num] = cols[j][num] = boxes[boxIndex][num] = true;
                }
            }
    
            return true;
        }
    };