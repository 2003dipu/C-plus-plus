// Tic Tac Toe in C++
#include <iostream>
#include <ctime>

void drawBoard(char *spaces) // 14 lines of code
{
    std::cout << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << '\n';
}
void playerMove(char *spaces, char player) // 15 lines of code
{
    int number;
    do
    {
        std::cout << "Enter a spot to place a marker (1-9): ";
        std::cin >> number;
        number--;
        if (spaces[number] == ' ' || spaces[number] > 9 || spaces[number] < 0)
        {
            spaces[number] = player;
            break;
        }
    } while (!number > 0 || !number < 8);
}
void computerMove(char *spaces, char computer) // 15 lines of code
{
    int number;
    srand(time(0));

    while (true)
    {
        number = rand() % 9;
        if (spaces[number] == ' ')
        {
            spaces[number] = computer;
            break;
        }
    }
}
bool checkWinner(char *spaces, char player, char computer) // 41 lines of code
{
    if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2]))
    {
        spaces[0] == player ? std::cout << "YOU WIN!\nYour Points: 1\nComputer's Points: 0\n" : std::cout << "YOU LOSE!\nComputer Wins\nComputer's Points: 1\nYour Points: 0\n";
    }
    else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5]))
    {
        spaces[3] == player ? std::cout << "YOU WIN!\nYour Points: 1\nComputer's Points: 0\n" : std::cout << "YOU LOSE!\nComputer Wins\nComputer's Points: 1\nYour Points: 0\n";
    }
    else if ((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8]))
    {
        spaces[6] == player ? std::cout << "YOU WIN!\nYour Points: 1\nComputer's Points: 0\n" : std::cout << "YOU LOSE!\nComputer Wins\nComputer's Points: 1\nYour Points: 0\n";
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6]))
    {
        spaces[0] == player ? std::cout << "YOU WIN!\nYour Points: 1\nComputer's Points: 0\n" : std::cout << "YOU LOSE!\nComputer Wins\nComputer's Points: 1\nYour Points: 0\n";
    }
    else if ((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7]))
    {
        spaces[1] == player ? std::cout << "YOU WIN!\nYour Points: 1\nComputer's Points: 0\n" : std::cout << "YOU LOSE!\nComputer Wins\nComputer's Points: 1\nYour Points: 0\n";
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8]))
    {
        spaces[2] == player ? std::cout << "YOU WIN!\nYour Points: 1\nComputer's Points: 0\n" : std::cout << "YOU LOSE!\nComputer Wins\nComputer's Points: 1\nYour Points: 0\n";
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8]))
    {
        spaces[0] == player ? std::cout << "YOU WIN!\nYour Points: 1\nComputers Points: 0\n" : std::cout << "YOU LOSE!\nComputer Wins\nComputer's Points: 1\nYour Points: 0\n";
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6]))
    {
        spaces[2] == player ? std::cout << "YOU WIN!\nYour Points: 1\nComputer's Points: 0\n" : std::cout << "YOU LOSE!\nComputer Wins\nComputer's Points: 1\nYour Points: 0\n";
    }
    else
    {
        return false;
    }

    return true;
}
bool checkTie(char *spaces) // 12 lines of code
{
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == ' ')
        {
            return false;
        }
    }
    std::cout << "IT'S A TIE!\n";
    return true;
}

int main() // 41 lines of code
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
        if (checkWinner(spaces, player, computer))
        {
            running = false;
            break;
        }
        else if (checkTie(spaces))
        {
            running = false;
            break;
        }

        playerMove(spaces, player);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer))
        {
            running = false;
            break;
        }
        else if (checkTie(spaces))
        {
            running = false;
            break;
        }
    }
    std::cout << "Thanks for playing!\n";

    return 0;
}// 143 lines of code
