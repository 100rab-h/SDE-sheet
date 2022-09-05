class Solution {
public:
    bool bfs(vector<vector<int>> &graph, vector<int> &col, int s) {
        queue<pair<int, int>> q;
        q.push({s, col[s]});
        
        while (!q.empty()) {
            int u = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int x : graph[u]) {
                if (col[x] == c) return false;
                if (col[x] == -1) {
                    col[x] = (c) ? 0 : 1;
                    q.push({x, col[x]});
                }
            }
        }
        
        return true;
    }
    
    bool dfs(vector<vector<int>> &graph, int s, vector<int> &col) {
        
        for (int x : graph[s]) {
            if (col[x] == col[s]) return false;
            if (col[x] == -1) {
                col[x] = col[s] ? 0 : 1;
                if (dfs(graph, x, col) == false) return false;
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> col(v, -1);
        
        for (int i = 0; i < v; i++) {
            if (col[i] == -1) {
                col[i] = 0;
                // if (bfs(graph, col, i) == false) return false;
                if (dfs(graph, i, col) == false) return false;
            }
        }
        
        return true;
    }
};
