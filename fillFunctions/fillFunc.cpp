
// what is a fill() function? = Fills a range of elements with a specified value > fill(begin, end, value)
/*
// code----------------------------Example---------1
#include <iostream>

int main()
{
    const int SIZE = 9;
    std::string foods[SIZE];
    //challenge project => fulfill the 1/3 with Thaipong, 1/3 with Jambura, 1/3 with Chambhut
    fill(foods, foods + (SIZE / 3), "....Thaipong");
    fill(foods + (SIZE / 3), foods + (SIZE / 3) * 2, "........Jumbura");
    fill(foods + (SIZE / 3) * 2, foods + SIZE, "....Chambhut");
    for (std::string food : foods)
    {
        std::cout << food << "\n";
    }

    return 0;
}
*/
// code----------------------------Example---------2
// How to fill an array with user input?

#include<iostream>
 
int main()
{
    std::string foods[5];
    int size = sizeof(foods)/sizeof(foods[0]);
    std::string temp;

    for(int i = 0; i < size; i++){
        std::cout << "Enter in food you like or 'q' to exit #" << i + 1 << ": ";
        std::getline(std::cin, temp);
        if(temp == "q"){
            break;
        }
        else{
            foods[i] = temp;
        }
    }

    std::cout << "You like the following food:\n";

    for(int i = 0; !foods[i].empty(); i++){
        std::cout << foods[i] << '\n';
    }

    return 0;
}

// code----------------------------Example---------3
// Using class to increase readability
/*
#include <iostream>
#include <string>

class FoodOrderService
{
public:
    void welcomeMessage()
    {
        std::cout << "\n------------Welcome to Online Food Order Service\n"
                  << "-----------Enter any 4 food items you like---------------\n";
    }

    void getFoodPreferences()
    {
        for (int i = 1; i < sizeA; i++)
        {
            std::cout << "Enter a food you like: #" << i << ": ";
            std::getline(std::cin, foods[i]);
        }
    }

    void displayFoodPreferences()
    {
        std::cout << "You like the following food: \n";
        for (std::string food : foods)
        {
            std::cout << food << "\n";
        }
    }

    void goodbyeMessage()
    {
        std::cout << "\n--------------------------------------------------------------------------------------------\n";
    }

    void run()
    {
        welcomeMessage();
        getFoodPreferences();
        displayFoodPreferences();
        goodbyeMessage();
    }

private:
    std::string foods[5];
    int sizeA = sizeof(foods) / sizeof(foods[0]);
};

int main()
{
    FoodOrderService foodOrderService;
    foodOrderService.run();

    return 0;
}
*/
// code----------------------------Example---------4
/*
#include <iostream>
#include <string>

class FoodOrderService {
public:
    void run() {
        std::cout << "\n------------------------------------------------------------------------------------------\n";
        std::cout << "\n------------Welcome to Online Food Order Service\n"
                  << "-----------Enter any 4 food items you like---------------\n";
        for (int i = 1; i < 5; i++) {
            std::cout << "Enter a food you like('q' to quit): #" << i << ": ";
            std::getline(std::cin, foods[i]);
        }
        std::cout << "\nYou like the following food: \n";
        for (int i = 1; i < 5; i++) {
            std::cout << foods[i] << "\n";
        }
        std::cout << "\n------------------------------------------------------------------------------------------\n";
    }
private:
    std::string foods[5];
};

int main() {
    FoodOrderService foodOS;
    foodOS.run();

    return 0;
}
*/
// code----------------------------Example---------5
/*
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::cout << "------------Welcome to Online Food Order Service------------\n";
    std::vector<std::string> foods; // Use a vector to store food items
    std::string input;

    while (true) {
        std::cout << "Enter a food you like (or 'quit' to exit): ";
        std::getline(std::cin, input);

        if (input == "quit") {
            break; // Exit the loop if the user enters 'quit'
        }

        foods.push_back(input); // Add the input to the vector
    }

    std::cout << "You like the following food: \n";
    for (const std::string& food : foods) {
        std::cout << food << "\n";
    }

    std::cout << "----------------------------------------------------------------------------------------------\n";
    return 0;
}
*/