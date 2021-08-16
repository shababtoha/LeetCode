class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row = false, col = false;
        for(int i = 0 ; i< matrix.size(); i++) {
            for(int j = 0; j< matrix[0].size(); j++) {
                if(!matrix[i][j]) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                    if(i == 0)
                        row = true;
                    if(j == 0)
                        col = true;
                }
            }
        }
        for(int i = 1 ; i< matrix.size(); i++) {
            for(int j = 1 ; j < matrix[0].size(); j++) {
                if(matrix[i][j]) {
                    matrix[i][j] = (matrix[0][j] ==0 || matrix[i][0] == 0) ? 0 : matrix[i][j];
                }
            }
        }
        for(int i = 0; i< matrix[0].size(); i++) {
            if(row)
                matrix[0][i] = 0;
                
        }
        for(int j = 0; j< matrix.size();j++) {
            if(col)
                matrix[j][0] = 0;
        }
        
    }
};