class Solution {
public:
    int f(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp) {
        if (ind == 0) {
            if (amount % coins[0] == 0) return amount / coins[0];
            return 1e9;
        }
        if (dp[ind][amount] != -1) return dp[ind][amount];
        
        int notTake = 0 + f(ind - 1, amount, coins, dp);
        int take = 1e9;
        if (amount >= coins[ind]) take = 1 + f(ind, amount - coins[ind], coins, dp);
        
        return dp[ind][amount] = min(take, notTake);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        // vector<vector<int>> dp(n, vector<int> (amount + 1, -1));
        // vector<vector<int>> dp(n, vector<int> (amount + 1, 0));
        // int ans = f(n - 1, amount, coins, dp);
        // if (ans == 1e9) return -1;
        // return ans;
        
        // vector<int> prev(amount + 1, 0), curr(amount + 1, 0);
        vector<int> prev(amount + 1, 0);
        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0) prev[j] = j / coins[0];
            else prev[j] = 1e9;
        }
        
//         for (int ind = 1; ind < n; ind++) {
//             for (int j = 0; j <= amount; j++) {
//                 int notTake = 0 + prev[j];
//                 int take = 1e9;
//                 if (j >= coins[ind]) take = 1 + curr[j - coins[ind]];

//                 curr[j] = min(take, notTake);
//             }
//             prev = curr;
//         }
//         int ans = prev[amount];
        
        for (int ind = 1; ind < n; ind++) {
            for (int j = 0; j <= amount; j++) {
                int notTake = 0 + prev[j];
                int take = 1e9;
                if (j >= coins[ind]) take = 1 + prev[j - coins[ind]];

                prev[j] = min(take, notTake);
            }
            // prev = curr;
        }
        int ans = prev[amount];
        if (ans == 1e9) return -1;
        return ans;
    }
};
