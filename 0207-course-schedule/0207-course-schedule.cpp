class Solution {
private:
    bool dfs(int node, vector<int> adj[], vector<int>& visited) {
        visited[node] = 1;
        for (auto neighbor : adj[node]) {
            if (visited[neighbor] == 1) {
                return false;
            }
            if (visited[neighbor] == 0) {
                if (!dfs(neighbor, adj, visited)) {
                    return false;
                }
            }
        }
        visited[node] = 2;
        return true;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (auto& pre : prerequisites) {
            int a = pre[0], b = pre[1];
            adj[b].push_back(a); 
        }
        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (!dfs(i, adj, visited)) {
                    return false;
                }
            }
        }
        return true;
    }
};