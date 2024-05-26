#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
char currentPlayer = 'X';

void displayBoard() {
    cout << "Current board state:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << "  " << board[i][j] << "  ";
            if (j < SIZE - 1) cout << "|";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "-----|-----|-----" << endl;
    }
    cout << endl;
}

bool isValidMove(int move) {
    int row = (move - 1) / SIZE;
    int col = (move - 1) % SIZE;
    return move >= 1 && move <= 9 && board[row][col] == ' ';
}

void makeMove(int move) {
    int row = (move - 1) / SIZE;
    int col = (move - 1) % SIZE;
    board[row][col] = currentPlayer;
}

bool checkWin() {
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }
    return false;
}

bool checkDraw() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void resetBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = ' ';
        }
    }
}

int main() {
    char playAgain;
    cout << "Welcome to the Tic-Tac-Toe game!" << endl;

    do {
        resetBoard();
        currentPlayer = 'X';
        bool gameWon = false;
        bool gameDraw = false;

        while (!gameWon && !gameDraw) {
            displayBoard();
            int move;
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            if (isValidMove(move)) {
                makeMove(move);
                gameWon = checkWin();
                if (!gameWon) {
                    gameDraw = checkDraw();
                    if (!gameDraw) {
                        switchPlayer();
                    }
                }
            } else {
                cout << "Invalid move. Try again. Please enter a number from 1 to 9." << endl;
            }
        }

        displayBoard();

        if (gameWon) {
            cout<<"\n-------------------------------------------\n";
            cout << "Player " << currentPlayer << " wins!" << endl;
            cout<<"-------------------------------------------\n";
        } else if (gameDraw) {
            cout << "The game is a draw!" << endl;
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing Tic-Tac-Toe!" << endl;

    return 0;
}
