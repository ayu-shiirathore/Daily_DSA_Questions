class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>> &vis, int delrow[], int delcol[]){
        vis[row][col] = 1;
        int m = board.size();
        int n = board[0].size();

        for(int i=0; i<4; i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow, ncol, board, vis, delrow, delcol);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n,0));

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        //travesrse first and last row
        for(int j=0; j<n; j++){
            //first row
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,board,vis,delrow,delcol);
            }
            //last row
            if(!vis[m-1][j] && board[m-1][j]=='O'){
                dfs(m-1,j,board,vis,delrow,delcol);
            }
        }

        //traverse first and last col
        for(int i=0; i<m; i++){
            //first col
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,board,vis,delrow,delcol);
            }
            //last col
            if(!vis[i][n-1] && board[i][n-1]=='O'){
                dfs(i,n-1,board,vis,delrow,delcol);
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && board[i][j] == 'O')
                    board[i][j]='X';
            }
        }
    }
};