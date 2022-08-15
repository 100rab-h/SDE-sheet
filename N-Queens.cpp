class Solution {
public:
    bool isSafe(vector<string> &board, int row, int col, int n) {
        int r = row;
        int c = col;
        
      // left side in same row.
        while (col >= 0) {
            if (board[row][col] == 'Q') return false;
            col--;
        }
        
      // upper left side.
        col = c;
        while(row >= 0 and col >= 0) {
            if (board[row][col] == 'Q') return false;
            col--;
            row--;
        }
        
      // lower left side.
        col = c;
        row = r;
        while (col >= 0 and row < n) {
            if (board[row][col] == 'Q') return false;
            col--;
            row++;
        }
        
        return true;
    }
    
    void solve(vector<string> &board, vector<vector<string>> &ans, int col, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        
        for (int row = 0; row < n; row++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                solve(board, ans, col + 1, n);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        solve(board, ans, 0, n);
        return ans;
    }
};
