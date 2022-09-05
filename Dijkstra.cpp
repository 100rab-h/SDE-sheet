public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});
        
        while (!pq.empty()) {
            int curr = pq.top().second;
            pq.pop();
            
            for (auto x : adj[curr]) {
                int u = x[0];
                int D = x[1];
                if (dist[u] > dist[curr] + D) {
                    dist[u] = dist[curr] + D;
                    pq.push({dist[u], u});
                }
            }
        }
        
        return dist;
    }
