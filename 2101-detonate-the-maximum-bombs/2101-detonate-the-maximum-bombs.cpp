class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for (int next : adj[node]) {
            if (!vis[next]) {
                dfs(next, adj, vis);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            long long x1 = bombs[i][0];
            long long y1 = bombs[i][1];
            long long r = bombs[i][2];
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                long long x2 = bombs[j][0];
                long long y2 = bombs[j][1];
                long long dx = x1 - x2;
                long long dy = y1 - y2;
                if (dx * dx + dy * dy <= r * r) {
                    adj[i].push_back(j);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> vis(n, 0);
            dfs(i, adj, vis);
            int cnt = 0;
            for (int x : vis)
                cnt += x;
            ans = max(ans, cnt);
        }
        return ans;
    }
};