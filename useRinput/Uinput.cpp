#include<iostream>
#include<string>
/*
// receive user input in c++
// cout <<(insertion operator);
// cin >>(extraction operator);

int main(){

    std::string name;
    std::cout << "What's your name? : ";
    std::cin >> name; // this cin can't accept anything after a white space
    std::cout << "Hello " << name << ". ";


    return 0;
}

#include<iostream>
#include<string>

int main() {

    std::cout << "-------------------------------------------------------------------- \n";
    std::cout << " \n";
    std::string name;
    int age;
    std::cout << "What's your full name? : ";
    std::getline(std::cin, name); // getline accepts multiple words with white spaces of any type which aren't possible with cin
    std::cout << "What's your age? : ";
    std::cin >> age;
    std::cout << " \n";
    std::cout << " \n";
    
    std::cout << "Hello " << name << ". \n";
    std::cout << "You are " << age << " years old. ";

    std::cout << " \n";
    std::cout << " \n";
    std::cout << "--------------------------------------------------------------------- \n";

    return 0;
}
*/

// if you use cin to receive user input before the getline, the result will be unintended. Here's the solution
int age;
std::string name;

int main(){

    std::cout << " \n\n";
    std::cout << "--------------------------------------------------------------------- \n"; //for design
    std::cout << "What's your age? ";
    std::cin >> age;
    std::cout << "What's your full name? ";
    std::getline(std::cin >> std::ws, name);

    std::cout << " \n";
    std::cout << "--------------------------------------------------------------------- \n";

    std::cout << "Hello " << name << ".\n";
    std::cout << "You are " << age << " years old.\n\n";

    std::cout << "--------------------------------------------------------------------- \n";
    return 0;
}

