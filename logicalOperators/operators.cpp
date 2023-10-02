
// ternary operators ?: = replacement to an if-else statement
// condition ? expression1 : expression 2
#include <iostream>
/*
// assignment 1
int main()
{
    
    int grade;
    std::cout << "What is your marks?: ";
    std::cin >> grade;
    
    if(grade > 40)
    {
        std::cout << "You passed.";
    }
    else
    {
        std::cout << "You failed";
    }
    // assignment 2
    
    // alternative to the above code:
    grade > 40 ? std::cout << "You passed." : std::cout << "You failed";

    return 0;
}
*/
// check if a number is even or odd
/*
// assignment 3
int main()
{
    
    int number;
    std::cout << "Enter a number to check even or odd: ";
    std::cin >> number;
    number % 2 == 1 ? std::cout << number << ": Odd." : std::cout << number << ": Even.";

    return 0;
}

// assignment 4
int main()
{
    
    bool qualified = true;
    qualified ? std::cout << "You are qualified! \n" : std::cout << "You are disqualified! \n";
    qualified = false;
    std::cout << (qualified ? "You are qualified!" : "You are disqualified!");
    return 0;
}

// assignment 5 (what are logical operators?)
// &&(and) check if at least one of two conditions is true.
// ||(or) check if one of the two conditions are true
// !(not or negation) = reverses the logical state of its operand.

int main()
{
    int temp;
    std::cout << "What's the current temperature in Celsius?: ";
    std::cin >> temp;
    if(temp > 0 && temp < 30){
        std::cout << "The current tempereature "<< temp << " degrees Celsius is good.";

    }
    else{
        std::cout << "The current tempereature " << temp << " degrees Celsius is bad.";
    }
    
    return 0;
}

// assignment 6

int main()
{
    std::cout << " \n";
    int temp;
    bool sunny = true;
    std::cout << "What's the current temperature in Celsius?: ";
    std::cin >> temp;
    if(temp <= 0 || temp >= 30){
        std::cout << "The current tempereature "<< temp << " degrees Celsius is bad! \n";
    }
    else{
        std::cout << "The current tempereature " << temp << " degrees Celsius is good! \n";
    }

    if(!sunny){
        std::cout << "The sky is sunny outside! \n\n";
    }
    else{
        std::cout << "The sky is cloudy outside!. \n\n";
    }
    return 0;
}

// assignment 7
// string interpolation 
// it shortens your codes. Let's apply it to the previous assignement
int main()
{

    std::cout << " \n";
    std::cout << "------------------------------------------------------------------------ \n";
    int temp;
    bool sunny = true;
    std::cout << "What's the current temperature in Celsius?: ";
    std::cin >> temp;
    if(temp <= 0 || temp >= 30){
        std::cout << "\nThe current tempereature "<< temp << " degrees Celsius is bad! \n";
    }
    else{
        std::cout << "\nThe current tempereature " << temp << " degrees Celsius is good! \n";
    }

    if(!sunny){
        std::cout << "The sky is sunny outside! \n";
    }
    else{
        std::cout << "The sky is cloudy outside!. \n";
    }
    
    std::cout << "------------------------------------------------------------------------ \n";
    std::cout << " \n";
    return 0;
}

// assignment 8 = C++ temperature conversion program. (Degree °)

int main()
{
    std::cout << "\n---------------*************Temperature Conversion****************------------- \n\n";
    std::cout << "(°F -> °C or  °C -> °F) \n";
    double temp;
    char unit;
    std::cout << "F = Fahrenheit \n";
    std::cout << "C = Celsius \n";
    std::cout << "What unit would you like to convert to?(F/C): ";
    std::cin >> unit;

    if (unit == 'F' || unit == 'f')
    {
        std::cout << "Enter the temperature in Celsius: ";
        std::cin >> temp;
        double fahrenheit = (temp * 9)/5 + 32.0;
        std::cout << "Temperature is: " << fahrenheit << "° F \n";
    }
    else if (unit == 'C' || unit == 'c')
    {
        std::cout << "Enter the temperature in Fahrenheit: ";
        std::cin >> temp;
        double celsius = 5*(temp - 32)/9;
        std::cout << "Temperature is: " << celsius << "° C \n";
    }
    else{
        std::cout << "Please enter in only C or F \n";
    }

    std::cout << "\n-------------------------------------------------------------------------------------- \n";
    return 0;
}
*/
// assignment 9 = Useful String methods in C++
// Nobody taught me the following useful string methods. I discovered them. These are really useful and can
// Myname is Dipu Singha. I am from Bangladesh. Contact me for programming help.
// change your programming skills and level up.
#include<iostream>

int main()
{
    std::cout << "\n-------------------------------------------------------------------------------------- \n";
    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    if(name.length() > 12){
        std::cout << "Your name can't be over 12 characters!";
        name.clear();
    }
    else if(name.empty()){
        std::cout << "You didn't enter your name!";
    }
    else{
        std::cout << "Welcome " << name << ".\nYour username is now: " << name.append("@gmail.com\n");
        std::cout << "As your name begins with " << name.at(0) << ", you are classified into group " << name.at(0);
        int index = name.find('@');
        int indexLast = name.find_last_of('m');
        name.erase(index, indexLast);
        std::cout << "\nYour twitter username is: " << name.insert(0, "@");
    }
    std::cout << "\n-------------------------------------------------------------------------------------- \n";
    return 0;
}
