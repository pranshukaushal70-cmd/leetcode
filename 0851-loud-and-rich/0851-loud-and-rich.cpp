class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto &r : richer){
            int a = r[0];
            int b = r[1];
            adj[a].push_back(b);
            indegree[b]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        vector<int> ans(n);
        for(int i = 0; i < n; i++)
            ans[i] = i;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int child : adj[node]){
                if(quiet[ans[node]] < quiet[ans[child]])
                    ans[child] = ans[node];
                indegree[child]--;
                if(indegree[child] == 0)
                    q.push(child);
            }
        }
        return ans;
    }
};