#include <iostream>
using namespace std;

char board[3][3]; // 3x3 Tic Tac Toe board

void initializeBoard() {
    char ch = '1';
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = ch++;
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        cout << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n-----------\n";
    }
    cout << "\n";
}

bool makeMove(int move, char player) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = player;
        return true;
    }
    return false;
}

char checkWin() {
    // Rows, Columns and Diagonals
    for (int i = 0; i < 3; ++i)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return board[i][0];
    for (int i = 0; i < 3; ++i)
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return board[0][i];
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return board[0][2];

    return ' '; // No winner yet
}

bool isDraw() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

int main() {
    initializeBoard();
    char currentPlayer = 'X';
    int move;

    while (true) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (move < 1 || move > 9 || !makeMove(move, currentPlayer)) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        char winner = checkWin();
        if (winner != ' ') {
            displayBoard();
            cout << "Player " << winner << " wins! \n";
            break;
        }

        if (isDraw()) {
            displayBoard();
            cout << "It's a draw!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
