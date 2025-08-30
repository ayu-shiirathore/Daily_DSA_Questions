class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int delrow[], int delcol[]) {
        vis[row][col] = 1;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && 
               !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, grid, vis, delrow, delcol);
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        // Mark land cells connected to top and bottom borders
        for(int j = 0; j < n; j++) {
            // Top border
            if(!vis[0][j] && grid[0][j] == 1) {
                dfs(0, j, grid, vis, delrow, delcol);
            }
            // Bottom border
            if(!vis[m-1][j] && grid[m-1][j] == 1) {
                dfs(m-1, j, grid, vis, delrow, delcol);
            }
        }
        
        // Mark land cells connected to left and right borders
        for(int i = 0; i < m; i++) {
            // Left border
            if(!vis[i][0] && grid[i][0] == 1) {
                dfs(i, 0, grid, vis, delrow, delcol);
            }
            // Right border
            if(!vis[i][n-1] && grid[i][n-1] == 1) {
                dfs(i, n-1, grid, vis, delrow, delcol);
            }
        }
        
        // Count land cells that are NOT connected to border
        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    count++;
                }
            }
        }
        
        return count;
    }
};