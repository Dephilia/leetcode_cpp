#include <leetcode.hpp>

class Solution {
public:
    bool dfs(vector<vector<char>>& board, const char* w, int x, int y, int& mx, int& my) {
        // Important: Use the reference of board instead copy it.
        if ( x < 0 ||
             y < 0 ||
             x >= mx ||
             y >= my ||
             *w != board[x][y] ||
             board[x][y] == '\0') return false;
        // cout << x << " " << y << endl;

        if ( *(w+1) == '\0') return true;
        char t = board[x][y]; // Note: The reference change the cell value, backup it.
        board[x][y] = '\0';

        if  ( dfs(board, w + 1, x + 1, y, mx, my) ||
              dfs(board, w + 1, x - 1, y, mx, my) ||
              dfs(board, w + 1, x, y + 1, mx, my) ||
              dfs(board, w + 1, x, y - 1, mx, my) ) {
            return true;
        }
        board[x][y] = t;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int mx = board.size(), my = board[0].size();
        for (int i=0; i<mx; i++) {
            for (int j=0; j<my; j++) {
                if (board[i][j] != word[0]) continue;
                if (dfs(board, word.c_str(), i, j, mx, my)) return true;

            }
        }
        return false;
    }
};

int main() {
    vector<vector<char>> board{
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    Solution sol;
    cout << sol.exist(board, "ABCCED") << endl;
    return 0;
}
