//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isValid(vector<vector<int>> &m, int i , int j, int n) {
        if (i < n and i >= 0 and j < n and j >= 0 and m[i][j] == 1) return true;
        return false;
    }
    
    void fun(vector<vector<int>> &m, int i, int j, int n, vector<string> &ans, string s) {
        if (i == n - 1 and j == n - 1 and m[i][j] == 1) {
            ans.push_back(s);
            return;
        }
        
        if (isValid(m, i, j, n)) {
            m[i][j] = 0;
            fun(m, i - 1, j, n, ans, s + 'U');
            fun(m, i + 1, j, n, ans, s + 'D');
            fun(m, i, j - 1, n, ans, s + 'L');
            fun(m, i, j + 1, n, ans, s + 'R');
            m[i][j] = 1;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string s;
        fun(m, 0, 0, n, ans, s);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
