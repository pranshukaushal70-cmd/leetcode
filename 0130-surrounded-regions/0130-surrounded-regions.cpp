class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int,int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bool isBoundary = (i == 0 || i == m-1 || j == 0 || j == n-1);
                if (isBoundary && board[i][j] == 'O') {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }
        int dirRow[] = {-1, 1, 0, 0};
        int dirCol[] = {0, 0, -1, 1};
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int newRow = row + dirRow[d];
                int newCol = col + dirCol[d];
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n 
                    && !visited[newRow][newCol] && board[newRow][newCol] == 'O') {
                    visited[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};