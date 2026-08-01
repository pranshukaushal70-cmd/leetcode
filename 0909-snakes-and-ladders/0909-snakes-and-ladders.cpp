class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<pair<int,int>> q;
        vector<bool> visited(n*n+1,false);
        q.push({1,0});
        visited[1]=true;
        while(!q.empty()){
            auto [square,moves]=q.front();
            q.pop();
            if(square==n*n)
                return moves;
            for(int dice=1;dice<=6;dice++){
                int next=square+dice;
                if(next>n*n)
                    break;
                int row=n-1-(next-1)/n;
                int col=(next-1)%n;
                if(((next-1)/n)%2==1)
                    col=n-1-col;
                if(board[row][col]!=-1)
                    next=board[row][col];
                if(!visited[next]){
                    visited[next]=true;
                    q.push({next,moves+1});
                }
            }
        }
        return -1;
    }
};