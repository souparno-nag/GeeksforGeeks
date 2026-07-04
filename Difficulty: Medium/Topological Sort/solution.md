# Solutions

## Topological sort with DFS

```cpp
class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adjList, int visited[], stack<int>& st, int V) {
        visited[node] = 1;
        for (int adj = 0; adj < V; adj++) {
            if (adjList[node][adj] == 1 && !visited[adj]) dfs(adj, adjList, visited, st, V);
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        int visited[V] = {0};
        stack<int> st;
        vector<vector<int>> adjList(V, vector<int>(V, 0));
        for (int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]][edges[i][1]] = 1;
        }
        for (int i = 0; i < V; i++) {
            if (!visited[i]) dfs(i, adjList, visited, st, V);
        }
        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};
```
