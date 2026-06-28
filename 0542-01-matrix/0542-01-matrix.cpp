class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1)); 
        queue<pair<int,int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
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
                    && dist[newRow][newCol] == -1) {
                    dist[newRow][newCol] = dist[row][col] + 1;
                    q.push({newRow, newCol});
                }
            }
        }   
        return dist;
    }
};