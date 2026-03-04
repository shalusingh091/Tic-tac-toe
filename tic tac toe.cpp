#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

// Function to reset board
void resetBoard() {
    char ch = '1';
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ch++;
        }
    }
}

// Display board
void displayBoard() {
    cout << "\n";
    for(int i = 0; i < 3; i++) {
        cout << " ";
        for(int j = 0; j < 3; j++) {
            cout << board[i][j];
            if(j < 2) cout << " | ";
        }
        cout << "\n";
        if(i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

// Switch player
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Check win
bool checkWin() {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == currentPlayer &&
           board[i][1] == currentPlayer &&
           board[i][2] == currentPlayer)
            return true;

        if(board[0][i] == currentPlayer &&
           board[1][i] == currentPlayer &&
           board[2][i] == currentPlayer)
            return true;
    }

    if(board[0][0] == currentPlayer &&
       board[1][1] == currentPlayer &&
       board[2][2] == currentPlayer)
        return true;

    if(board[0][2] == currentPlayer &&
       board[1][1] == currentPlayer &&
       board[2][0] == currentPlayer)
        return true;

    return false;
}

// Check draw
bool checkDraw() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

int main() {
    char playAgain;
    do {
        resetBoard();
        currentPlayer = 'X';
        bool gameOver = false;

        while(!gameOver) {
            displayBoard();
            int choice;
            cout << "Player " << currentPlayer << ", enter position (1-9): ";
            cin >> choice;

            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;

            if(choice < 1 || choice > 9 || 
               board[row][col] == 'X' || board[row][col] == 'O') {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            board[row][col] = currentPlayer;

            if(checkWin()) {
                displayBoard();
                cout << "?? Player " << currentPlayer << " wins!\n";
                gameOver = true;
            }
            else if(checkDraw()) {
                displayBoard();
                cout << "?? Game is a draw!\n";
                gameOver = true;
            }
            else {
                switchPlayer();
            }
        }

        cout << "Play again? (y/n): ";
        cin >> playAgain;

    } while(playAgain == 'y' || playAgain == 'Y');

    return 0;
}



/*Readme.md
# Tic Tac Toe Game (C++)

This is a console-based Tic Tac Toe game developed using C++.

## Features
- Two player game (X and O)
- 3x3 game board
- Win and draw detection
- Replay option

## How to Run
1. Open folder in VS Code
2. Compile:
   g++ main.cpp -o tictactoe
3. Run:
   ./tictactoe*/