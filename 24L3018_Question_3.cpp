#include <iostream>
#include <conio.h>
using namespace std;

/*
  CONSTANTS
  - Easy to adjust later if we expand the grid size or rules.
*/
const int BOARD_SIZE = 3;

/*
  Function: displayBoard
  Purpose : Prints the current 3x3 grid on screen.
*/
void displayBoard(char board[BOARD_SIZE][BOARD_SIZE])
{
    cout << endl;
    cout << "Current Board:" << endl;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            cout << " " << board[i][j] << " ";
            if (j < BOARD_SIZE - 1)
                cout << "|";
        }
        cout << endl;
        if (i < BOARD_SIZE - 1)
            cout << "---+---+---" << endl;
    }
    cout << endl;
}

/*
  Function: initializeBoard
  Purpose : Sets all positions to empty spaces.
*/
void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = ' ';
        }
    }
}

/*
  Function: checkWin
  Purpose : Checks if the current player has won.
  Returns : true if any row, column, or diagonal is filled.
*/
bool checkWin(char board[BOARD_SIZE][BOARD_SIZE], char symbol)
{
    // Check rows and columns
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol))
            return true;
    }

    // Check diagonals
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol))
        return true;

    return false;
}

/*
  Function: isDraw
  Purpose : Checks if all cells are filled (draw).
*/
bool isDraw(char board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

/*
  Function: makeMove
  Purpose : Handles player input for placing a mark.
  Returns : true if move is valid, false otherwise.
*/
bool makeMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, char symbol)
{
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE)
    {
        cout << "Invalid position! Please enter values between 1 and 3." << endl;
        return false;
    }

    if (board[row][col] != ' ')
    {
        cout << "Cell already taken! Try another position." << endl;
        return false;
    }

    board[row][col] = symbol;
    return true;
}

/*
  Function: playTicTacToe
  Purpose : Main game loop for two players.
*/
void playTicTacToe()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(board);

    char currentPlayer = 'X';
    bool gameOver = false;

    cout << "=== Tic-Tac-Toe ===" << endl;
    cout << "Player 1: X" << endl;
    cout << "Player 2: O" << endl;

    while (!gameOver)
    {
        displayBoard(board);

        cout << "Player " << currentPlayer << ", enter your move (row and column 1-3): ";
        int row, col;
        cin >> row >> col;

        // Adjust for 0-based index
        row--;
        col--;

        if (makeMove(board, row, col, currentPlayer))
        {
            // Check win
            if (checkWin(board, currentPlayer))
            {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOver = true;
            }
            // Check draw
            else if (isDraw(board))
            {
                displayBoard(board);
                cout << "Game drawn!" << endl;
                gameOver = true;
            }
            // Switch player
            else
            {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        cout << endl;
    }

    cout << "Press any key to exit..." << endl;
    getch();
}

/*
  Function: main
  Purpose : Entry point for the game.
*/
int main()
{
    playTicTacToe();
    return 0;
}
