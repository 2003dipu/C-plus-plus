// How I entered here today(26September2023) in Visual Studio Code to debug and run my C++ codes:
// command prompt ->1. mkdir projects -> 2.cd C:\Users\t\OneDrive\Desktop\projects ->
// -> 3. mkdir C++ConditionalStatements -> 4. cd C++ConditionalStatements -> 5. code . (press enter)
// 6. New File -> 7. Command Palette -> 8. C\C++: Select IntelliSense configuration
// 9. Use gcc.exe Found at C:\mysys64\ucrt64\bin ->10. .vscode Folder is created automatically
// 11. Click on triangular shape button at the upper-right corner: Debug C/C++ File
// 12. Select: C/C++: g++.exe build and debug active file preLaunchTask:C/C++:g++.exe build active file
// Detected Task(compiler: C:\mysys64\ucrt64\bin\g++.exe)
// That's it. Those above commands now debug and run my codes every time I click the triangular shape button.
/*
#include <iostream>

int main()
{

    // if statements = do something if a condition is true
    //               = if not then don't do it.
    std::cout << "---------------------------------------------------- \n\n";
    std::string name;

    int age;
    std::cout << "What's your name?: ";
    std::getline(std::cin, name);
    std::cout << "How old are you?: ";
    std::cin >> age;

    if (age >= 100)
    {
        std::cout << "You are too old to enter this site! \n";
    }
    else if (age < 18)
    {
        std::cout << "You must be 18 + to enter this site! \n";
    }
    else if (age >= 18)
    {
        std::cout << "Welcome! " << name << " You are signed up and can enter this site. \n";
    }
    else if (age > 0)
    {
        std::cout << "You haven't been born yet! \n";
    }
    else
    {
        std::cout << name << "Enter a valid age integer \n";
    }

    std::cout << "---------------------------------------------------- \n\n";

    return 0;
}

#include <iostream>
// switch statement

int main()
{
    std::cout << " \n";
    std::cout << "------------------------------------------------------------------------\n";
    // switch = alternative to using many else-if statements
    // compare one value against matching cases
    int month;
    std::cout << "Enter the month(1-12): ";
    std::cin >> month;

    switch (month)
    {
    case 1:
        std::cout << "It's January.";
        break;
    case 2:
        std::cout << "It's February.";
        break;
    case 3:
        std::cout << "It's March.";
        break;
    case 4:
        std::cout << "It's April.";
        break;
    case 5:
        std::cout << "It's May.";
        break;
    case 6:
        std::cout << "It's Jun.";
        break;
    case 7:
        std::cout << "It's July.";
        break;
    case 8:
        std::cout << "It's August.";
        break;
    case 9:
        std::cout << "It's September.";
        break;
    case 10:
        std::cout << "It's October.";
        break;
    case 11:
        std::cout << "It's November.";
        break;
    case 12:
        std::cout << "It's December.";
        break;
    default:
        std::cout << "Please enter in only number(1-12)";
    }
    std::cout << " \n";
    std::cout << "------------------------------------------------------------------------\n\n";
    return 0;
}
*/

#include<iostream>

int main()
{
    std::cout << " \n";
    std::cout << "------------------------------------------------------------------------\n";
    char grade;
    std::cout << "What letter grade did you get from your C# exam? ";
    std::cin >> grade;
    switch(grade)
    {
        case 'A':
            std::cout << "You did great in C# certification exam by freeCodeCamp and Microsoft!";
            break;
        case 'B':
            std::cout << "You did good in C# certification exam by freeCodeCamp and Microsoft!";
            break;
        case 'C':
            std::cout << "You did okay in C# certification exam by freeCodeCamp and Microsoft!";
            break;
        case 'D':
            std::cout << "You did not do good in C# certification exam by freeCodeCamp and Microsoft!";
            break;
        case 'E':
            std::cout << "You need further improvement before taking in C# certification exam by freeCodeCamp and Microsoft!";
            break;
        case 'F':
            std::cout << "You failed to pass in C# certification exam by freeCodeCamp and Microsoft!";
            break;
        default:
            std::cout << "Please only enter in letter grade(A-F)";

    }

    std::cout << " \n";
    std::cout << "------------------------------------------------------------------------\n\n";
    return 0;
}