class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        int area = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j] = 1;
                    int count = 0;
                    while (!q.empty()) {
                        auto [row, col] = q.front();
                        q.pop();
                        count++;
                        for (int k = 0; k < 4; k++) {
                            int nrow = row + delRow[k];
                            int ncol = col + delCol[k];
                            if (nrow >= 0 && nrow < n &&
                                ncol >= 0 && ncol < m &&
                                !vis[nrow][ncol] &&
                                grid[nrow][ncol] == 1) {
                                vis[nrow][ncol] = 1;
                                q.push({nrow,ncol});
                            }
                        }
                    }
                    area = max(area, count);
                }
            }
        }
        return area;
    }
};