class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // build the adjacency list
        vector<vector<int>> adjList(V);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        // calculate shortest distances using bfs
        vector<int> dist(V, INT_MAX);
        queue<int> q;
        dist[src] = 0;
        q.push(src);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int adj : adjList[node]) {
                if (dist[node] != INT_MAX && dist[node] + 1 < dist[adj]) {
                    dist[adj] = 1 + dist[node];
                    q.push(adj);
                }
            }
        }
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) dist[i] = -1;
        }
        return dist[dest];
    }
};