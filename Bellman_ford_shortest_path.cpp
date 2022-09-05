class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        // Code here
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        for (int count = 0; count < V - 1; count++) {
            for (auto x : adj) {
                int u = x[0];
                int v = x[1];
                int d = x[2];
                if (dist[u] != 1e8) {
                    if (dist[v] > dist[u] + d) {
                        dist[v] = dist[u] + d;
                    }
                }
            }
        }
        
        return dist;
    }
};
