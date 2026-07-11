class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;
        pq.push({0, src, 0});
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            int cost = cur[0];
            int node = cur[1];
            int stops = cur[2];
            if(node == dst)
                return cost;
            if(stops == k + 1)
                continue;
            for(auto &it : adj[node]){
                int nextNode = it.first;
                int wt = it.second;
                if(cost + wt < dist[nextNode][stops + 1]){
                    dist[nextNode][stops + 1] = cost + wt;
                    pq.push({cost + wt, nextNode, stops + 1});
                }
            }
        }
        return -1;
    }
};