public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> dist(V, 1e8);
        dist[0] = 0;
        vector<bool> mst(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            mst[u] = true;
            
            for (auto x : adj[u]) {
                int v = x[0];
                int d = x[1];
                if (!mst[v] and dist[v] > d) {
                    dist[v] = d;
                    pq.push({d, v});
                }
            }
        }
        return accumulate(dist.begin(), dist.end(), 0);
        
    }
