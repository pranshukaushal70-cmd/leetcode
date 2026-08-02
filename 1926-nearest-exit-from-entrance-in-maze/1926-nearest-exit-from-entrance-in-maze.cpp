class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,pair<int,int>>> q;
        int n = maze.size();
        int m = maze[0].size();
        int drow[] = {-1,1,0,0};
        int dcol[] = {0,0,-1,1};
        int r = entrance[0];
        int c = entrance[1];
        q.push({0,{r,c}});
        maze[r][c] = '+';
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            int move = node.first;
            int i = node.second.first;
            int j = node.second.second;
            bool isBoundary = (i==0 || i==n-1 || j==0 || j==m-1);
            if((i!=r || j!=c) && isBoundary)
                return move;
            for(int k=0;k<4;k++) {
                int delrow = i + drow[k];
                int delcol = j + dcol[k];
                if(delrow>=0 && delrow<n &&
                   delcol>=0 && delcol<m &&
                   maze[delrow][delcol]=='.') {
                    maze[delrow][delcol] = '+';
                    q.push({move+1,{delrow,delcol}});
                }
            }
        }
        return -1;
    }
};