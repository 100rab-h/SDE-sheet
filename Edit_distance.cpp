class Solution {
public:
    int f(int i, int j, string &word1, string &word2, vector<vector<int>> &dp) {
        // if (i < 0 and j < 0) return 0;
        if (i == 0) return j;
        if (j == 0) return i;
        if (dp[i][j] != -1) return dp[i][j];
        
        if (word1[i - 1] == word2[j - 1]) return dp[i][j] = 0 + f(i - 1, j - 1, word1, word2, dp);
        else {
            return dp[i][j] = 1 + min(f(i - 1, j - 1, word1, word2, dp), min(f(i - 1, j, word1, word2, dp), f(i, j - 1, word1, word2, dp)));
        }
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        // vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        // return f(n, m, word1, word2, dp);
        
        // vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        // dp[0][0] = 0;
        // for (int i = 1; i <= n; i++) dp[i][0] = i;
        // for (int  j = 1; j <= m; j++) dp[0][j] = j;
        for (int  j = 1; j <= m; j++) prev[j] = j;
        
        for (int i = 1; i <= n; i++) {
            curr[0] = i;
            for (int j = 1; j <= m; j++) {
                // if (word1[i - 1] == word2[j - 1]) dp[i][j] = 0 + dp[i - 1][j - 1];
                // else dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                if (word1[i - 1] == word2[j - 1]) curr[j] = 0 + prev[j - 1];
                else curr[j] = 1 + min(prev[j - 1], min(prev[j], curr[j - 1]));
            }
            prev = curr;
        }
        // return dp[n][m];
        
        return prev[m];
    }
};
