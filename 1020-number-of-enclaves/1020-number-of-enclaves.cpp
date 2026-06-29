class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int,int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bool isBoundary = (i == 0 || i == m-1 || j == 0 || j == n-1);
                if (isBoundary && grid[i][j] == 1) {
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
                    && !visited[newRow][newCol] && grid[newRow][newCol] == 1) {
                    visited[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
};