class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> rownum(n, 0);
        vector<int> colnum(m, 0);
        int count = 0;
        
        // Count number of servers in each row and column
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    rownum[i]++;
                    colnum[j]++;
                }
            }
        }

        // Now count the servers that can communicate (i.e., have other servers in their row or column)
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && (rownum[i] > 1 || colnum[j] > 1)) {
                    sum++;
                }
            }
        }

        return sum;
    }
};