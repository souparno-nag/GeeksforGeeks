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

## Topological Sort with Kahn's algorithm

```cpp
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        int indegree[V] = {0};
        vector<vector<int>> adjList (V, vector<int>());
        
        for (int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
        }
        for (int node = 0; node < V; node++) {
            for (int adj : adjList[node]) {
                indegree[adj]++;
            }
        }
        
        queue<int> q;
        for (int node = 0; node < V; node++) {
            if (indegree[node] == 0) q.push(node);
        }
        
        vector<int> result;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);
            
            for (int adj : adjList[node]) {
                indegree[adj]--;
                if (indegree[adj] == 0) q.push(adj);
            }
        }
        
        return result;
    }
};
```
