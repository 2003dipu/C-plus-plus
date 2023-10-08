// This game doens't implement the AI instead it enables two players to play. To implement minimax algorithm in C++ is a daunting task
// I did it with python, however, with C++ it's way difficult. -> Disclaimer

#include <iostream>
using namespace std;

// Define the board size and the symbols for the players
const int N = 3;
const char X = 'X';
const char O = 'O';
const char EMPTY = '-';

// Declare a global variable to store the board state
char board[N][N];

// Initialize the board with empty symbols
void init_board()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = EMPTY;
        }
    }
}

// Print the board to the standard output
void print_board()
{
    cout << "  ";
    for (int j = 0; j < N; j++)
    {
        cout << j + 1 << " ";
    }
    cout << "\n";
    for (int i = 0; i < N; i++)
    {
        cout << i + 1 << " ";
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

// Check if a given move is valid
bool is_valid(int row, int col)
{
    return row >= 0 && row < N && col >= 0 && col < N && board[row][col] == EMPTY;
}

// Check if a given player has won the game
bool is_winner(char player)
{
    // Check rows
    for (int i = 0; i < N; i++)
    {
        bool win = true;
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] != player)
            {
                win = false;
                break;
            }
        }
        if (win)
            return true;
    }
    // Check columns
    for (int j = 0; j < N; j++)
    {
        bool win = true;
        for (int i = 0; i < N; i++)
        {
            if (board[i][j] != player)
            {
                win = false;
                break;
            }
        }
        if (win)
            return true;
    }
    // Check diagonals
    bool win = true;
    for (int i = 0; i < N; i++)
    {
        if (board[i][i] != player)
        {
            win = false;
            break;
        }
    }
    if (win)
        return true;
    win = true;
    for (int i = 0; i < N; i++)
    {
        if (board[i][N - i - 1] != player)
        {
            win = false;
            break;
        }
    }
    return win;
}

// Check if the board is full
bool is_full()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == EMPTY)
            {
                return false;
            }
        }
    }
    return true;
}

// Play a tic tac toe game between two human players
void play_game()
{

    // Initialize the board and print it
    init_board();

    cout << "Welcome to Tic Tac Toe!\n";

    print_board();

    // Define the current player and the move coordinates
    char player = X;

    int row, col;

    // Loop until the game is over
    while (true)
    {
        // Prompt the current player to enter a move
        cout << "Player " << player << ", enter your move (row): ";
        cin >> row;
        cout << "Player " << player << ", enter your move (column): ";
        cin >> col;

        // Adjust the indices to start from zero
        row--;
        col--;

        // Validate the move and update the board
        if (is_valid(row, col))
        {
            board[row][col] = player;

            // Print the board after the move
            print_board();

            // Check if the current player has won or the board is full
            if (is_winner(player))
            {
                cout << "Player " << player << " wins!\n";

                break;
            }
            else if (is_full())
            {
                cout << "It's a tie!\n";
                break;
            }
            else
            { // Switch to the other player
                player = (player == X) ? O : X;
            }
        }
        else
        { // The move was invalid, ask again
            cout << "Invalid move, try again.\n";
        }
    }
}

// The main function
int main()
{

    // Call the play_game function
    play_game();

    return 0;
}