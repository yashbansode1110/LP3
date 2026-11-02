
#include <iostream>
using namespace std;

int board[20][20];
int n;

bool isSafe(int row, int col) {

    // Check same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper left diagonal
    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check upper right diagonal
    for (int i = row - 1, j = col + 1;
         i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueens(int row) {

    if (row == n)
        return true;

    for (int col = 0; col < n; col++) {

        if (isSafe(row, col)) {

            board[row][col] = 1;

            if (solveNQueens(row + 1))
                return true;

            // Backtracking
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int firstCol;

    cout << "Enter value of N: ";
    cin >> n;

    cout << "Enter first queen column (0 to "
         << n - 1 << "): ";
    cin >> firstCol;

    if (n < 1 || n > 20 ||
        firstCol < 0 || firstCol >= n) {
        cout << "Invalid input";
        return 0;
    }

    // Place first queen in row 0
    board[0][firstCol] = 1;

    if (solveNQueens(1)) {

        cout << "\nN-Queens Solution:\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "No solution possible";
    }

    return 0;
}
