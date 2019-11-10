class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int total = 0;
        int col = colsum.size();
        
        for (int i=0; i<col; i++){
            total += colsum[i];
        }
        vector<vector<int>> emp(0, vector<int>(0,0));
        if (total != upper + lower) return emp;
        vector<vector<int>> arry(2, vector<int>(col, 0));
        int tmp_upper_sum = 0;
        int tmp_low_sum = 0;
        for (int j=0; j<col; j++){
            if (colsum[j] == 0){
                arry[0][j] = 0;
                arry[1][j] = 0;
             }
            else if (colsum[j] == 2) {
                arry[0][j] = 1;
                arry[1][j] = 1;
                tmp_upper_sum += 1;
                tmp_low_sum += 1;
                
            }
            else if (colsum[j] == 1) {
                if (upper-tmp_upper_sum>= lower-tmp_low_sum){
                    arry[0][j] = 1;
                    arry[1][j] = 0;
                    tmp_upper_sum += 1;
                } else {
                    arry[0][j] = 0;
                    arry[1][j] = 1;
                    tmp_low_sum += 1;
                }
            }
        }
        if ((upper-tmp_upper_sum != 0) || (lower-tmp_low_sum != 0)) return emp;
        return arry;
    }
};