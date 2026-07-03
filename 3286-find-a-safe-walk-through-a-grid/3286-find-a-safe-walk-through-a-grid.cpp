class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> best(m, vector<int>(n, -1));
        queue<pair<pair<int,int>, int>> q;
        int startHealth = health - grid[0][0];
        if(startHealth <= 0) return false;
        q.push({{0, 0}, startHealth});
        best[0][0] = startHealth;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int row = it.first.first;
            int col = it.first.second;
            int currHealth = it.second;
            if(row == m-1 && col == n-1)
                return true;
            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n) {
                    int newHealth = currHealth - grid[nrow][ncol];
                    if(newHealth > 0 && newHealth > best[nrow][ncol]) {
                        best[nrow][ncol] = newHealth;
                        q.push({{nrow, ncol}, newHealth});
                    }
                }
            }
        }
        return false;
    }
};