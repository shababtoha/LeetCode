class Solution {
    int getSquareNo(int n, int m) {
        return (n/3) * 3 + m/3;
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0};
        int col[9][9] = {0};
        int sqaure[9][9] = {0};
        if(board.size() != 9) {
            return false;
        }
        for(int i = 0; i<9; i++) {
            
            if(board[i].size() != 9) {
                return false;
            }
            for(int j = 0 ; j <9; j++) {
                if(board[i][j] == '.') {
                    continue;
                }
                int value = board[i][j] - '1';
                int squareNo = getSquareNo(i, j);
                if(row[i][value] || col[j][value] || sqaure[squareNo][value]) {
                    return false;
                }
                row[i][value] = col[j][value] = sqaure[squareNo][value] = true;
            }
        }
        return true;
    }
};