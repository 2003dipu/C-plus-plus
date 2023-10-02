
/*
// rock paper scissors game in C++
#include <iostream>
// --------------------------------------------------------Function 1
char getUserChoice()
{

    std::cout << "                  Rock-Paper-Scissors Game \n";
    char player;
    do
    {
        std::cout << "\n----------------------------------------------------------------\n";
        std::cout << "****************************************************************\n\n";
        std::cout << "Choose one of the following.\n";
        std::cout << "'r' for rock\n'p' for paper\n's' for scissors\n->: ";
        std::cin >> player;
    } while (player != 'r' && player != 'p' && player != 's');

    return player;
}
// --------------------------------------------------------Function 2
char getComputerChoice()
{
    srand(time(0));
    int randNum = rand() % 3 + 1;
    switch (randNum)
    {
    case 1:
        return 'r';
    case 2:
        return 'p';
    case 3:
        return 's';
    }
    return 0;
}
// --------------------------------------------------------Function 3
void showChoice(char choice)
{
    switch (choice)
    {
    case 'r':
        std::cout << "Rock\n";
        break;
    case 'p':
        std::cout << "Paper\n";
        break;
    case 's':
        std::cout << "Scissors\n";
    }
}
// --------------------------------------------------------Function 4
void chooseWinner(char player, char computer)
{

    switch (player)
    {
    case 'r':
        if (computer == 'r')
        {
            std::cout << "It's a tie!";
        }
        else if (computer == 'p')
        {
            std::cout << "You lose!";
        }
        else if (computer == 's')
        {
            std::cout << "You win!";
        }
        break;
    case 'p':
        if (computer == 'r')
        {
            std::cout << "You win!";
        }
        else if (computer == 'p')
        {
            std::cout << "It's a tie!";
        }
        else if (computer == 's')
        {
            std::cout << "You lose!";
        }
        break;
    case 's':
        if (computer == 'r')
        {
            std::cout << "You lose!";
        }
        else if (computer == 'p')
        {
            std::cout << "You win!";
        }
        else if (computer == 's')
        {
            std::cout << "It's a tie!";
        }
        break;
    default:
        break;
    }
}
// --------------------------------------------------------Function 5 (main function that executes the code)
int main()
{
    std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| \n";
    char player;
    char computer;
    player = getUserChoice();
    std::cout << "Your choice:-------------> ";
    showChoice(player);
    computer = getComputerChoice();
    std::cout << "Computer's choice: ------> ";
    showChoice(computer);
    chooseWinner(player, computer);
    std::cout << "\n-----------------------------------------------------------------\n";
    std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";

    return 0;
}
*/
// alternative code with class
#include <iostream>
#include <cstdlib>
#include <ctime>

class GameFunctions
{
public:
    char getUserChoice()
    {
        char player;
        do
        {
            std::cout << "\n----------------------------------------------------------------\n";
            std::cout << "****************************************************************\n\n";
            std::cout << "Choose one of the following.\n";
            std::cout << "'r' for rock\n'p' for paper\n's' for scissors\n->: ";
            std::cin >> player;
        } while (player != 'r' && player != 'p' && player != 's');

        return player;
    }

    char getComputerChoice()
    {
        srand(time(0));
        int randNum = rand() % 3 + 1;
        switch (randNum)
        {
        case 1:
            return 'r';
        case 2:
            return 'p';
        case 3:
            return 's';
        }
        return 0;
    }

    void showChoice(char choice)
    {
        switch (choice)
        {
        case 'r':
            std::cout << "Rock\n";
            break;
        case 'p':
            std::cout << "Paper\n";
            break;
        case 's':
            std::cout << "Scissors\n";
            break;
        }
    }

    void chooseWinner(char player, char computer)
    {
        if (player == computer)
        {
            std::cout << "It's a tie!";
        }
        else if ((player == 'r' && computer == 's') ||
                 (player == 'p' && computer == 'r') ||
                 (player == 's' && computer == 'p'))
        {
            std::cout << "You win!";
        }
        else
        {
            std::cout << "You lose!";
        }
    }

    void playGame()
    {
        std::cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| \n";
        char player = getUserChoice();
        std::cout << "Your choice:-------------> ";
        showChoice(player);
        char computer = getComputerChoice();
        std::cout << "Computer's choice: ------> ";
        showChoice(computer);
        chooseWinner(player, computer);
        std::cout << "\n-----------------------------------------------------------------\n";
        std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
    }
};

int main()
{
    GameFunctions game;
    game.playGame();
    return 0;
}
