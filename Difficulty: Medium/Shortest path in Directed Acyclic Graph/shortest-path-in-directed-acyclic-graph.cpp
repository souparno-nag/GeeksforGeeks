class Solution {
  private:
    void topoSort(int node, vector<vector<pair<int, int>>>& adjList, stack<int>& st, vector<bool>& visited) {
        visited[node] = true;
        for (auto adj : adjList[node]) {
            int v = adj.first;
            if (!visited[v]) topoSort(v, adjList, st, visited);
        }
        st.push(node);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // obtain adjacency list from edges
        vector<vector<pair<int, int>>> adjList(V);
        for (int i = 0; i < E; i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adjList[u].push_back({v, w});
        }
        // find the topological sort
        vector<bool> visited(V, false);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) topoSort(i, adjList, st, visited);
        }
        // calculate the distances
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            
            for (auto adj : adjList[node]) {
                int v = adj.first, w = adj.second;
                if (dist[node] != INT_MAX && dist[node] + w < dist[v]) dist[v] = w + dist[node];
            }
        }
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        }
        return dist;
    }
};
