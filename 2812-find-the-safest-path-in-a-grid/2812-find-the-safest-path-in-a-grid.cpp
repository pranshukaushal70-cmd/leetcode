class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nr=r+dr[k],nc=c+dc[k];
                if(nr>=0&&nr<n&&nc>=0&&nc<n&&dist[nr][nc]==INT_MAX){
                    dist[nr][nc]=dist[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
        priority_queue<pair<int,pair<int,int>>> pq;
        vector<vector<int>> best(n,vector<int>(n,-1));
        pq.push({dist[0][0],{0,0}});
        best[0][0]=dist[0][0];
        while(!pq.empty()){
            auto cur=pq.top();
            pq.pop();
            int safe=cur.first,r=cur.second.first,c=cur.second.second;
            if(r==n-1&&c==n-1)return safe;
            if(safe<best[r][c])continue;
            for(int k=0;k<4;k++){
                int nr=r+dr[k],nc=c+dc[k];
                if(nr>=0&&nr<n&&nc>=0&&nc<n){
                    int ns=min(safe,dist[nr][nc]);
                    if(ns>best[nr][nc]){
                        best[nr][nc]=ns;
                        pq.push({ns,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};
