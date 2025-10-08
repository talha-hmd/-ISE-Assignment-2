#include <iostream>
#include <conio.h>
using namespace std;

/*
  CONSTANTS
  - Easy to modify later for grid size or rules.
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
  Purpose : Checks if all cells are filled (draw condition).
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
  Function: getValidMove
  Purpose : Gets and validates player input safely.
  Robustness: Handles non-numeric and out-of-range inputs.
*/
void getValidMove(int &row, int &col)
{
    while (true)
    {
        cout << "Enter your move (row and column 1-3): ";
        if (cin >> row >> col)
        {
            // Convert to 0-based index
            row--;
            col--;

            if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE)
                break;
            else
                cout << "Invalid range! Please enter values between 1 and 3." << endl;
        }
        else
        {
            cout << "Invalid input! Please enter two numbers." << endl;
            cin.clear();            // Clear error state
            cin.ignore(1000, '\n'); // Discard invalid input
        }
    }
}

/*
  Function: playTicTacToe
  Purpose : Main game loop for two players.
  Robustness: Validates all inputs and prevents crash.
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

        int row, col;
        cout << "Player " << currentPlayer << "'s turn." << endl;

        getValidMove(row, col);

        if (makeMove(board, row, col, currentPlayer))
        {
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
  Purpose : Allows replay and controls program flow.
*/
int main()
{
    char choice;

    do
    {
        playTicTacToe();

        cout << "Do you want to play again? (Y/N): ";
        cin >> choice;
        choice = toupper(choice);

        // Clear buffer for safety
        cin.clear();
        cin.ignore(1000, '\n');

    } while (choice == 'Y');

    cout << "Program exited successfully." << endl;
    return 0;
}
