class Solution {
public:
    bool f(int ind, int sum, vector<int> &nums, vector<vector<int>> &dp) {
        if (ind == 0) {
            if (sum == 0 or nums[0] - sum == 0) return true;
            else return false;
        }
        if (dp[ind][sum] != -1) return dp[ind][sum];
        
        bool notTake = f(ind - 1, sum, nums, dp);
        bool take = false;
        if (sum >= nums[ind]) take = f(ind - 1, sum - nums[ind], nums, dp);
        
        return dp[ind][sum] = take | notTake;
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        sum = sum / 2;
        // vector<vector<int>> dp(n, vector<int> (sum + 1, -1));
        // return f(n - 1, sum, nums, dp);
        
        // vector<vector<int>> dp(n, vector<int> (sum + 1, 0));
        
        vector<int> prev(sum + 1, 0); // curr(sum + 1, 0);
        // dp[0][0] = true;
        prev[0] = true;
        
        // for(int j = 1; j <= sum; j++) {
        //     if (nums[0] - j == 0) dp[0][j] = true;
        //     else dp[0][j] = false;
        // }
        for(int j = 1; j <= sum; j++) {
            if (nums[0] - j == 0) prev[j] = true;
            else prev[j] = false;
        }
        
        for (int ind = 1; ind < n; ind++) {
            // for (int j = 0; j <= sum; j++) {
            for (int j = sum; j >= 0; j--) {
//                 bool notTake = dp[ind - 1][j];
//                 bool take = false;
//                 if (j >= nums[ind]) take = dp[ind - 1][j - nums[ind]];

//                 dp[ind][j] = take | notTake;
                
// //            ----------     space Optimization     -------
//                 bool notTake = prev[j];
//                 bool take = false;
//                 if (j >= nums[ind]) take = prev[j - nums[ind]];

//                 curr[j] = take | notTake;
//             }
//             prev = curr;
                
//                 ----- 1D Array SO -------
                bool notTake = prev[j];
                bool take = false;
                if (j >= nums[ind]) take = prev[j - nums[ind]];

                prev[j] = take | notTake;
            }
                
        }
        
        // return dp[n - 1][sum];
        return prev[sum];
    }
};
