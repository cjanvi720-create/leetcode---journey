class Solution {
public:
    vector<vector<string>> ans;
    void solve(int col, int n, vector<string>& board, vector<int>& leftRow, vector<int>& upperDiag, vector<int>& lowerDiag) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for(int row = 0;  row < n; row++) {
            if(!leftRow[row] && !lowerDiag[row + col] && !upperDiag[n - 1 + col - row]) {
                board[row][col] = 'Q';
                leftRow[row] = lowerDiag[row+col] = upperDiag[n - 1 + col - row] = 1;

                solve(col + 1, n, board, leftRow, upperDiag, lowerDiag);
                board[row][col] = '.';
                leftRow[row] = lowerDiag[row + col] = upperDiag[n - 1 + col - row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n,0), upperDiag(2 * n - 1, 0), lowerDiag(2 * n - 1, 0);
        solve(0, n, board, leftRow, upperDiag, lowerDiag);
        return ans;
    }
};
