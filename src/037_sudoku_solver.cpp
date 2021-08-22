/*
 * This is a DFS problem.
 * Try to use recursive function to solve.
 *
 */
#include <leetcode.hpp>

// Just for convenience
using Board = vector<vector<char>>;

bool isValid(Board& board, int& row, int& col, char& ch) {
    /*
     * Input row, column and char, determine if the char is valid
     */

    // Check row
    for (auto& i:board) {
        if (i[col] == ch) return false;
    }

    // Check column
    for (auto& i:board[row]) {
        if (i == ch) return false;
    }

    // Check 3x3 Box
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            char val = board[row/3*3+i][col/3*3+j];
            if (val == ch) return false;
        }
    }

    return true;
}

bool solveOnce(Board& board, int num) {
    // If overboard, return true (complete solving)
    if (num < 0 || num > 80) return true;

    // If the block is solved, move to next block
    int row = num / 9;
    int col = num % 9;
    if (board[row][col] != '.') return solveOnce(board, num+1);

    // Try to fill the block with 1 to 9
    for (char ch='1'; ch <= '9'; ch++){
        if (isValid(board, row, col, ch)) {
            // If the number is valid, fill it and move to next
            board[row][col] = ch; // Set state
            if (solveOnce(board, num+1)) return true;
            // If next state never become true, it means the number is wrong.
            board[row][col] = '.'; // Important, reset state
        }
    }
    return false;
}

void solveSudoku(Board& board) {
    solveOnce(board,0);
}


/*
 * Main
 */

void printBoard(vector<vector<char>>& board) {
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}


int main() {
    vector<vector<char>> board{
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    solveSudoku(board);
    printBoard(board);
    return 0;
}
