class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();       
        int m = board[0].size();     
        vector<vector<int>> dir = {
            {-1,-1}, {-1,0}, {-1,1},
            {0,-1},          {0,1},
            {1,-1},  {1,0},  {1,1}
        };
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int liveNeighbors = 0;
                for(auto d : dir) {
                    int ni = i + d[0];
                    int nj = j + d[1];
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        if(board[ni][nj] == 1 || board[ni][nj] == -1)
                            liveNeighbors++;
                    }
                }
                if(board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3))
                    board[i][j] = -1;
                if(board[i][j] == 0 && liveNeighbors == 3)
                    board[i][j] = 2;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] > 0)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            }
        }
    }
};