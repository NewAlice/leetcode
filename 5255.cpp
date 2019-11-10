class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> ary(n, vector<int>(m, 0));
        int row;
        int col;
        int result = 0;
        for (int i=0; i<indices.size(); i++){
             if (indices[i][0] > n || indices[i][1] > m){
                 return result;
             }
             for (int j=0; j<m; j++){
                 row = indices[i][0];
                 ary[row][j] += 1;
             }
            for (int k=0; k<n; k++){
                col = indices[i][1];
                ary[k][col] += 1;
            }
        }
        for (int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (ary[i][j]%2 != 0) result++;
            }
        }
        return result;
    }
};