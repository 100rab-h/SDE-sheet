class Solution {
public:
    int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if (i == 0 and j == 0) return grid[0][0];
        if (i < 0 or j < 0) return 1e9;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int up = grid[i][j] + f(i - 1, j, grid, dp);
        int left = grid[i][j] + f(i, j - 1, grid, dp);
        
        return dp[i][j] = min(up, left);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // vector<vector<int>> dp(m, vector<int> (n, -1));
        // return f(m - 1, n - 1, grid, dp);
        
//         ------    Tabulation    -------
        
//         vector<vector<int>> dp(m, vector<int> (n, 0));
        
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (i == 0 and j == 0) dp[i][j] = grid[i][j];
//                 else {
//                     int up = 1e9, left = 1e9;
//                     if (i > 0) up = grid[i][j] + dp[i - 1][j];
//                     if (j > 0) left = grid[i][j] + dp[i][j - 1];

//                     dp[i][j] = min(up, left);
//                 }
                
//             }       
//         }
//         return dp[m - 1][n - 1];
        
//         ----- Space Optimization ---- 
        
        vector<int> prev(n, 0), curr(n, 0);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 and j == 0) curr[j] = grid[i][j];
                else {
                    int up = 1e9, left = 1e9;
                    if (i > 0) up = grid[i][j] + prev[j];
                    if (j > 0) left = grid[i][j] + curr[j - 1];

                    curr[j] = min(up, left);
                }
                
            }       
            prev = curr;
        }
        return prev[n - 1];
        
    }
};
