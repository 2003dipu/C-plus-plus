// My name is Dipu Singha. I created this game in C++ on 29 September 2023 after having my lunch.
// C++ number guessing Game
#include <iostream>
#include <ctime>

int main()
{
    std::cout << "\n--------------------------------------------------------------\n";
    std::cout << "************** Welcome to Number Guessing Game!!! **************\n";
    srand(time(0));
    int cgRn = 1 + rand() % 1000 + 1; // Generate a random integer between 1-1000
    int userGuess;
    int guessCount;
    do
    {
        std::cout << "Guess the number computer generated randomly: ";
        std::cin >> userGuess;
        guessCount += 1;
        if (cgRn == userGuess)
        {
            std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
            std::cout << "\nYou are a genius intelligent human being.\nYou win!\n";
            if (guessCount < 5)
            {
                std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
                std::cout << "You are lucky this time.You get a diamond. Because...................\n";
                std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
                std::cout << "\nThis round took you only " << guessCount << " Try. Unlock your diamond!\n";
            }
            else if (guessCount < 15)
            {
                std::cout << "\nThis round took you only " << guessCount << " Try. You get gold\n";
                std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
            }
            
            else
            {
                std::cout << "\nThis round took you " << guessCount << " Try.\n Poor performance though\n";
            }
        }
        else if (userGuess > cgRn)
        {
            std::cout << "Guess more lower to win!\n";
            if (guessCount > 20)
            {
                std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
                std::cout << "->*************GAME OVERYOU************YOU LOSE!!!.................<-\n";
                std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
                std::cout << "\n              Try Again?\n";
                break;
            }
            else if (guessCount > 10)
            {
                std::cout << "\nWARNING!!! : You have already used " << guessCount << " Try. Be careful!\n";
            }
            else
            {
                std::cout << "\nYou have already used " << guessCount << " Try\n";
            }
        }
        else if (userGuess < cgRn)
        {
            std::cout << "Guess more higher to win!\n";
            if (guessCount > 20)
            {
                std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
                std::cout << "->**************GAME OVER************YOU LOSE!!!...............<-\n";
                std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
                std::cout << "\n              Try Again?\n";
                break;
            }
            else if (guessCount > 10)
            {
                std::cout << "\nWARNING!!! : You have already used " << guessCount << " Try\n";
            }
            else
            {
                std::cout << "\nYou have already used " << guessCount << " Try\n";
            }
        }
        else
        {
            std::cout << "Please read the game instructions above and enter in only integer number!";
        }

    } while (cgRn != userGuess);

    std::cout << "\n--------------------------------------------------------------\n";
    return 0;
}
// The End.