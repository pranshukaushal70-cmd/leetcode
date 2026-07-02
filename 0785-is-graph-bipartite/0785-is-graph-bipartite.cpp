class Solution {
public:
    bool bfs(int start, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int adj : graph[node]) {
                if (color[adj] == -1) {
                    color[adj] = 1 - color[node];
                    q.push(adj);
                }
                else if (color[adj] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!bfs(i, graph, color))
                    return false;
            }
        }
        return true;
    }
};