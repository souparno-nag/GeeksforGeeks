class Solution {
    vector<int> topoSort(int V, vector<vector<int>>& adjList) {
        int indegree[V] = {0};
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
  public:
    string findOrder(vector<string> &words) {
        vector<int> seen(26, 0);
        int letterCount = 0;
        
        for (string& word : words) {
            for (char c : word) {
                if (!seen[c - 'a']) {
                    seen[c - 'a'] = 1;
                    letterCount++;
                }
            }
        }

        vector<vector<int>> adjList(26, vector<int>());
        
        for (int i = 0; i < words.size()-1; i++) {
            string s1 = words[i], s2 = words[i+1];
            int len = min(s1.length(), s2.length());
            bool found = false;
            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adjList[s1[j] - 'a'].push_back(s2[j] - 'a');
                    found = true;
                    break;
                }
            }
            if (!found && s1.length() > s2.length())
                return "";
        }
        
        vector<int> topo = topoSort(26, adjList);
        string ans = "";
        for (int ch : topo) {
            if (seen[ch]) ans += ('a' + ch);
        }
        if (ans.length() != letterCount) return "";
        return ans;
    }
};