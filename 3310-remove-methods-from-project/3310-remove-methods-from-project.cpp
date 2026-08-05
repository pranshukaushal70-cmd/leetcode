class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);
        vector<int> ans;
        queue<int> q;
        for(auto &it : invocations){
            int a = it[0];
            int b = it[1];
            adj[a].push_back(b);
        } 
        q.push(k);
        vis[k] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int x : adj[node]){
                if(!vis[x]){
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }
        bool hasContradiction = false;
        for(auto &it : invocations){
            int x = it[0];
            int y = it[1];
            if(vis[x] == 0 && vis[y] == 1){
                hasContradiction = true;
                break;
            }
        }
        if(hasContradiction){
            for(int i = 0; i < n; i++) ans.push_back(i);
        } else {
            for(int i = 0; i < n; i++){
                if(vis[i] == 0) ans.push_back(i);
            }
        }
        return ans;
    }
};