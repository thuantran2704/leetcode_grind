class Solution {
public:
    void transform(vector<vector<char>>& board, int i, int j){
        int n = board.size();
        int m = board[0].size();
        if(i < 0 || j < 0 || i == n || j == m || board[i][j] != 'O') return;
        board[i][j] = '#';

        transform(board, i-1, j);
        transform(board, i+1, j);
        transform(board, i, j-1);
        transform(board, i, j+1);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i =0  ; i < n;i++){
            if(board[i][0] == 'O') transform(board, i, 0);
            if(board[i][m-1] == 'O') transform(board, i, m-1);
        }

        for(int j = 0; j < m;j++){
            if(board[0][j] == 'O') transform(board, 0, j);
            if(board[n-1][j] == 'O') transform(board, n-1, j);
        }

        for(int i = 0 ; i < n;i++){
            for(int j = 0 ; j < m;j++){
                if(board[i][j] == '#') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
