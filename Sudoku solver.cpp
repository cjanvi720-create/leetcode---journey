class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char num){
        for(int i = 0; i < 9; i++) {
            //row check
            if(board[row][i] == num) return false;

            //column check
            if(board[i][col] == num) return false;

            // 3*3 box check
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == num)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {

                if(board[i][j] == '.') {
                    for(char c = '1'; c <= '9'; c++) {

                        if(isValid(board, i, j, c)) {
                            board[i][j] = c;

                            if(solve(board))
                                return true;

                                //backtrack
                                board[i][j] = '.';
                        }
                    }
                    return false;// no valid no. found
                }
            }
        }
        return true;//solved
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
