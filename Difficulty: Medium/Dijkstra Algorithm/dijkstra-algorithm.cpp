class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // prepare the adjacency list
        vector<vector<pair<int, int>>> adjList(V);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }
        // prepare data structures
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(V, 1e9);
        // initialize
        dist[src] = 0;
        pq.push({0, src});
        // calculate the distances
        while (!pq.empty()) {
            int dis = pq.top().first, node = pq.top().second;
            pq.pop();
            if (dis != dist[node]) continue;
            for (auto it: adjList[node]) {
                int adjNode = it.first, edgeWeight = it.second;
                if (dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};