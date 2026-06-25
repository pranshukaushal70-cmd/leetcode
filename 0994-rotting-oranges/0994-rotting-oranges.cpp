class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int freshCount = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = 2;
                } else {
                    vis[i][j] = 0;
                }
                if (grid[i][j] == 1) freshCount++;
            }
        }
        int tm = 0;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        int countRotten = 0;
        while (!q.empty()) {
            int sz = q.size();
            bool rottedThisRound = false;
            for (int i = 0; i < sz; i++) {
                auto [row, col] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int nrow = row + delrow[d];
                    int ncol = col + delcol[d];
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                        && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2) {
                        vis[nrow][ncol] = 2;
                        q.push({nrow, ncol});
                        countRotten++;
                        rottedThisRound = true;
                    }
                }
            }
            if (rottedThisRound) tm++;
        }
        if (countRotten != freshCount) return -1;

        return tm;
    }
};