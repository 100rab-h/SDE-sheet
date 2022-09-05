#include<bits/stdc++.h>
void dfs(vector<int> adj[], int s, vector<bool> &visited, stack<int> &st) {
    visited[s] = true;
    for (int x : adj[s]) {
        if (!visited[x]) dfs(adj, x, visited, st);
    }
    
    st.push(s);
}

void revDfs(vector<int> revAdj[], int s, vector<bool> &visited, vector<int> &temp) {
    visited[s] = true;
    temp.push_back(s);
    for (int x : revAdj[s]) {
        if (!visited[x]) revDfs(revAdj, x, visited, temp);
    }
    
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int> adj[n];
    for (auto x : edges) {
        adj[x[0]].push_back(x[1]);
    }
    
    
    
    stack<int> st;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs(adj, i, visited, st);
    }
    
    vector<int> revAdj[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        for (int x : adj[i]) {
            revAdj[x].push_back(i);
        }
    }
      
    vector<vector<int>> ans;
    while (!st.empty()) {
        int curr = st.top();
        st.pop();
        if (!visited[curr]) {
            vector<int> temp;
            revDfs(revAdj, curr, visited, temp);
            ans.push_back(temp);
        }
    }
    
    return ans;
    
}
