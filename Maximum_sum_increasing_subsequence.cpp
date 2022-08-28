//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	
	int f(int ind, int prev, int arr[], int n, vector<vector<int>> &dp) {
	    if (ind == n) return 0;
	    if (dp[ind][prev + 1] != -1) return dp[ind][prev + 1];
	    
	    int notTake = 0 + f(ind + 1, prev, arr, n, dp); 
	    int take = 0;
	    if (prev == -1 or arr[prev] < arr[ind]) take = arr[ind] + f(ind + 1, ind, arr, n, dp);
	    
	    return dp[ind][prev + 1] = max(take, notTake);
	}
	
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	   // vector<vector<int>> dp(n, vector<int> (n, -1));
	   // return f(0, -1, arr, n, dp);
	   
	   //vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
	   vector<int> front(n + 1, 0), curr(n + 1, 0);
	   
	   for (int ind = n - 1; ind >= 0; ind--) {
	       for (int prev = ind - 1; prev >= -1; prev--) {
	           //int notTake = 0 + dp[ind + 1][prev + 1]; 
        	   // int take = 0;
        	   // if (prev == -1 or arr[prev] < arr[ind]) take = arr[ind] + dp[ind + 1][ind + 1];
        	    
        	   // dp[ind][prev + 1] = max(take, notTake);
        	   
        	   int notTake = 0 + front[prev + 1]; 
        	    int take = 0;
        	    if (prev == -1 or arr[prev] < arr[ind]) take = arr[ind] + front[ind + 1];
        	    
        	    curr[prev + 1] = max(take, notTake);
            }
            front = curr;
	   }
	   
	   //return dp[0][-1 + 1];
	   return front[-1 + 1];
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
