class Solution {
public:
    bool isSafe(vector<vector<char>> &board, int row, int col, char num, int n) {
        for (int d = 0; d < n; d++) {
            if (board[row][d] == num) return false;
        }
        
        for (int r = 0; r < n; r++) {
            if (board[r][col] == num) return false;
        }
        
        int s = (int)sqrt(n);
        int boxRowStart = row - row % s;
        int boxColStart = col - col % s;
        
        for (int r = boxRowStart; r < boxRowStart + s; r++) {
            for (int d = boxColStart; d < boxColStart + s; d++) {
                if (board[r][d] == num) return false;
            }
        }
        
        return true;
    }
    
    bool solve(vector<vector<char>> &board, int n) {
        int row = -1;
        int col = -1;
        
        bool isEmpty = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    row = i;
                    col = j;
                    isEmpty = false;
                    break;
                }
            }
            if (!isEmpty) break;
        }
        
        if (isEmpty) return true;
        
        for (char num = '1'; num <= '9'; num++) {
            if (isSafe(board, row, col, num, n)) {
                board[row][col] = num;
                if (solve(board, n)) return true;
                else board[row][col] = '.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        int i = 0, j = 0;
        int n = board.size();
        
        if (solve(board, n)) {
            return;    
        }
        
        return;
    }
};
