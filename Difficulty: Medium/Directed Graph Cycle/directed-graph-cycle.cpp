class Solution {
  public:
    bool dfs(vector<vector<int>> &adj, int node, vector<bool>& visited, vector<bool>& pathVisited) {
        visited[node] = true;
        pathVisited[node] = true;
        
        for (int neighbour: adj[node]) {
            if (pathVisited[neighbour]) return true;
            if (!visited[neighbour]) {
                if (dfs(adj, neighbour, visited, pathVisited)) return true;
            }
        }
        
        pathVisited[node] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<bool> visited(V, false), pathVisited(V, false);
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
        }
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(adj, i, visited, pathVisited)) return true;
            }
        }
        return false;
    }
};