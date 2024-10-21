#include <iostream>
#include <vector>
using namespace std;

// Size of the board
const int N = 4;

// Function to print the chessboard
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 0) {
                cout << ". ";
            } else if (board[i][j] == 1) {
                cout << "Q ";
            } else {
                cout << "P "; // Represents the placed queen
            }
        }
        cout << endl;
    }
}

// Function to check if it's safe to place a queen at board[pos_x][pos_y]
bool is_safe(const vector<vector<int>>& board, int pos_x, int pos_y) {
    // Check the column
    for (int i = 0; i < N; i++) {
        if (board[i][pos_y] == 1) {
            return false;
        }
    }

    // Check the row
    for (int i = 0; i < N; i++) {
        if (board[pos_x][i] == 1) {
            return false;
        }
    }

    // Check upper left diagonal
    for (int i = pos_x, j = pos_y; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check lower left diagonal
    for (int i = pos_x, j = pos_y; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check upper right diagonal
    for (int i = pos_x, j = pos_y; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check lower right diagonal
    for (int i = pos_x, j = pos_y; i < N && j < N; i++, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Backtracking function to place the queens
bool NQueens(vector<vector<int>>& board, int col, pair<int, int> placed) {
    if (col >= N) {
        return true;
    }

    // Skip the column where the first queen is placed
    if (col == placed.second) {
        return NQueens(board, col + 1, placed);
    }

    // Try to place a queen in each row of the current column
    for (int i = 0; i < N; i++) {
        if (i == placed.first) {
            continue; // Skip the row where the first queen is placed
        }

        if (is_safe(board, i, col)) {
            board[i][col] = 1; // Place the queen

            if (NQueens(board, col + 1, placed)) {
                return true; // If placement is successful, return true
            }

            board[i][col] = 0; // Backtrack if not successful
        }
    }

    return false; // No valid placement found
}

int main() {
    // Initialize the chessboard
    vector<vector<int>> board(N, vector<int>(N, 0));

   // Input position for the first queen
    int p1, p2;
    cout << "Enter the position where 1st queen is placed (row col):";
    cin >> p1 >> p2;
    // Check for valid input
    if (p1 < 0 || p1 >= N || p2 < 0 || p2 >= N) {
        cout << "Invalid position! Please enter values between 0 and " << N-1 << "." << endl;
        return 1; // Exit if the position is invalid
    }

    // Place the first queen at the specified position
    pair<int, int> placed = {p1, p2};
    board[placed.first][placed.second] = 1;

    cout << "Initial Board" << endl;
    printBoard(board);
    cout << "********" << endl;

    // Start solving for the remaining queens
    if (NQueens(board, 0, placed)) {
        cout << "Solution" << endl;
        printBoard(board);
        cout << "********" << endl;
    } else {
        cout << "No Solution" << endl;
    }

    return 0;
}
