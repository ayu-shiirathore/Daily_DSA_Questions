class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int size = m*n;

        // step1 : create a position vector for each element of the matrix
        unordered_map<int, pair<int, int>> pos;
        // store matrix in this hashMap:
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pos[mat[i][j]] = {i, j};
            }
        }   

        //find earliest row or column painted
        vector<int> rowcount(m,0);
        vector<int> colcount(n,0);
        for(int i=0;i<size;i++){
            pair<int,int> coordinate = pos[arr[i]];
            int x= coordinate.first;
            int y= coordinate.second;
            rowcount[x]++;
            colcount[y]++;
            if(rowcount[x]==n || colcount[y]==m)
            return i;
        }
        return -1;
    }
};
