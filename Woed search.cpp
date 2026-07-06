#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool dfs(vector<vector<char>>& b, string& w, int r, int c, int i) {
        if (i == w.length()) return true;
        if (r < 0 || c < 0 || r >= b.size() || c >= b[0].size() || b[r][c] != w[i]) return false;

        char temp = b[r][c];
        b[r][c] = '*';

        bool found = dfs(b, w, r+1, c, i+1) || dfs(b, w, r-1, c, i+1) || dfs(b, w, r, c+1, i+1) || dfs(b, w, r, c-1, i+1);
        b[r][c] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int r = 0; r < board.size(); r++)
            for (int c = 0; c < board[0].size(); c++)
                if (dfs(board, word, r, c, 0)) return true;
        return false;
    }
};
