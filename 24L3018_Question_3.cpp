#include <iostream>
#include <conio.h>
using namespace std;

// Display the current board
void displayBoard(char board[3][3])
{
    cout << "\nCurrent Board:\n\n";
    for (int i = 0; i < 3; i++)
    {
        cout << " ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];
            if (j < 2)
                cout << " | ";
        }
        cout << endl;
        if (i < 2)
            cout << "---+---+---" << endl;
    }
    cout << endl;
}

// Check if a player has won
bool checkWin(char board[3][3], char player)
{
    // Check rows and columns
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || // row 
        (board[0][i] == player && board[1][i] == player && board[2][i] == player))   // column
            return true;
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

// Check if board is full (draw)
bool isDraw(char board[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}

int main()
{
    char board[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' '; // initializing empty board

    char currentPlayer = 'X';
    int row, col;
    bool gameOver = false;

    cout << "=== Tic-Tac-Toe ===" << endl;
    cout << "Player 1: X\nPlayer 2: O\n" << endl;

    while (!gameOver)
    {
        displayBoard(board);

        cout << "Player " << currentPlayer << ", enter your move (row and column 1-3): ";
        cin >> row >> col;

        // Input validation
        if (row < 1 || row > 3 || col < 1 || col > 3)
        {
            cout << "Invalid position! Try again.\n";
            continue;
        }

        // Adjusting for 0-indexed array
        row--;
        col--;

        // Check if space already occupied
        if (board[row][col] != ' ')
        {
            cout << "That cell is already taken! Try again.\n";
            continue;
        }

        // Make the move
        board[row][col] = currentPlayer;

        // Check for win
        if (checkWin(board, currentPlayer))
        {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameOver = true;
        }
        // Check for draw
        else if (isDraw(board))
        {
            displayBoard(board);
            cout << "Game Drawn!" << endl;
            gameOver = true;
        }
        // Switch player
        else
        {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    cout << "\nPress any key to exit...";
    getch();
    return 0;
}
