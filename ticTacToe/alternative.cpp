// Tic Tac Toe in C++
#include <iostream>
#include <ctime>

const int BOARD_SIZE = 3;
void drawBoard(char *spaces) // 9 lines of code
{
    std::cout << "\n";
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        std::cout << "     |     |     \n  " << spaces[i * BOARD_SIZE + 0] << "  |  " << spaces[i * BOARD_SIZE + 1] 
        << "  |  " << spaces[i * BOARD_SIZE + 2] << "  \n_____|_____|_____\n";
    }
    std::cout << "\n";
}

void playerMove(char *spaces, char player) // 11 lines of code
{
    int number;
    do
    {
        std::cout << "Enter a spot to place a marker (1-9): ";
        std::cin >> number;
        number--;
    } while (spaces[number] != ' ' || number < 0 || number > 8);
    spaces[number] = player;
}
void computerMove(char *spaces, char computer) // 10 lines of code
{
    int number;
    srand(time(0));
    do
    {
        number = rand() % 9;
    } while (spaces[number] != ' ');
    spaces[number] = computer;
}
// 32 lines to 9 lines

bool checkWinner(char *spaces, char player, char computer)// 14 lines of code
{// possible winning combinations
    int win[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}}; // 2D array
    for (int i = 0; i < 8; i++)
    {                               // loop through each combination
        char c = spaces[win[i][0]]; // get the first character of the combination
        if ((c != ' ') && (c == spaces[win[i][1]]) && (c == spaces[win[i][2]]))
        {// check if all three characters are the same and not empty | // print the result
            std::cout << (c == player ? "YOU WIN!\nYour Points: 1\nComputer's Points: 0\n" : 
            "YOU LOSE!\nComputer Wins\nComputer's Points: 1\nYour Points: 0\n");
            return true;// return true to indicate a winner
        }
    }
    return false; // return false to indicate no winner
}

bool checkTie(char *spaces) // 10 lines of code
{
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == ' ')
            return false;
    }
    std::cout << "IT'S A TIE!\n";
    return true;
}

int main() // 40 lines of code
{
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;
    drawBoard(spaces);

    while (running)
    {
        computerMove(spaces, computer);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer) || checkTie(spaces))
        {
            running = false;
            break;
        }

        playerMove(spaces, player);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer) || checkTie(spaces))
        {
            running = false;
            break;
        }
    }
    std::cout << "Thanks for playing!\n";

    return 0;
} // 96 lines of code