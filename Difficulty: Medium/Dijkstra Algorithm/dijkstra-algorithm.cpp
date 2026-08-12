class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // prepare the adjacency list
        vector<vector<pair<int, int>>> adjList(V+1);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }
        // prepare data structures
        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);
        // initialize
        dist[src] = 0;
        st.insert({0, src});
        // calculate the distances
        while (!st.empty()) {
            auto it = *(st.begin());
            int dis = it.first, node = it.second;
            st.erase(it);
            for (auto it: adjList[node]) {
                int adjNode = it.first, edgeWeight = it.second;
                if (dis + edgeWeight < dist[adjNode]) {
                    if (dist[adjNode] != 1e9) {
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = dis + edgeWeight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};