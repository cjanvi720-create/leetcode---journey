class Solution {
public:
    int totalNQueens(int n, int rows = 0, int cols = 0, int diag1 = 0, int diag2 = 0) {
        if (rows == n) return 1;
        int count = 0;
        int availablePositions = ((1 << n) - 1) & ~(cols | diag1 | diag2);

        while (availablePositions) {
            int p = availablePositions & -availablePositions;
            availablePositions -= p;
            count += totalNQueens(n, rows + 1, cols | p, (diag1 | p) << 1, (diag2 | p) >> 1);
        }
        return count;
    }
};
