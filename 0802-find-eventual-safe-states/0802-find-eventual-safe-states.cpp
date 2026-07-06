class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adjrev[n];
        vector<int> indegree(n, 0);
        for(int i=0; i<n; i++){
            // i->it
            //it->i
            for(int it : graph[i]){
                adjrev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            ans.push_back(temp);
            for(int in : adjrev[temp]){
                indegree[in]--;
                if(indegree[in]==0){
                    q.push(in);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};