/*
// How to create a random number generator?
// pseudo-random = Not truly random(but close)
#include<iostream>

int main()
{
    std::cout << "\n----------------------------------------------------------- \n";
    srand(time(NULL));
    //int num;
    //std::cout << "Set the higher bound of a range: ";
    //std::cin >> num;
    int num1 = 5 + (rand() % 10) + 1; // generate a random number between 1 and 6(1-6) Formula = (1-n).Here n=6
    int num2 = (rand() % 6) + 1;
    int num3 = (rand() % 6) + 1;
    std::cout << "Randomly generated number is: " << num1 << " \n";
    std::cout << "Randomly generated number is: " << num2 << " \n";
    std::cout << "Randomly generated number is: " << num3 << " \n";

    std::cout << "\n----------------------------------------------------------- \n";
    return 0;
}
*/
//--------------------------------------------------------------------- Exercise - 2
// Random event generator in C++
#include <iostream>
#include <ctime>

int main()
{
    std::cout << "\n----------------------------------------------------------- \n";

    srand(time(0));
    int randNum = rand() % 11 + 1;
    // std::cout << randNum;
    switch (randNum)
    {
    case 1:
        std::cout << "You win a bumper sticker!\n";
        break;
    case 2:
        std::cout << "You win a laptop!\n";
        break;
    case 3:
        std::cout << "You win an iPhone!\n";
        break;
    case 4:
        std::cout << "You win a house!\n";
        break;
    case 5:
        std::cout << "You win a 1 million dollar!\n";
        break;
    case 6:
        std::cout << "You win a free lunch!\n";
        break;
    case 7:
        std::cout << "You meet your romantic reliable colleague at Google!\n";
        break;
    case 8:
        std::cout << "You are chosen by Microsoft!\n";
        break;
    case 9:
        std::cout << "You get a software engineer job at Google!\n";
        break;
    case 10:
        std::cout << "You win a good pair programmer!\n";
        break;
    case 11:
        std::cout << "You get a job at DeepMind!\n";
        break;
    }

    std::cout << "\n----------------------------------------------------------- \n";
    return 0;
}
