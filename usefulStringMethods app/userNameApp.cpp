
// from the user's name, determine the user's twitter and gmail name.
// assignment 9 = Useful String methods in C++
// Nobody taught me the following useful string methods. I discovered them. These are really useful and can
// Myname is Dipu Singha. I am from Bangladesh. Contact me for programming help.
// change your programming skills and level up.
#include <iostream>
#include <algorithm> // For std::transform

int main() {
    std::cout << "\n-------------------------------------------------------------------------------------- \n";
    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    // Remove whitespace and convert to lowercase
    name.erase(std::remove_if(name.begin(), name.end(), ::isspace), name.end());
    std::transform(name.begin(), name.end(), name.begin(), ::tolower);

    if (name.length() > 15) {
        std::cout << "Your name can't be over 15 characters!";
        name.clear();
    } else if (name.empty()) {
        std::cout << "You didn't enter your name!";
    } else {
        std::cout << "Welcome " << name << ".\nYour email is : " << name << "@gmail.com\n";
        std::cout << "As your name begins with " << name.at(0) << ", you are classified into group " << name.at(0);

        // Find the index of '@' and the last occurrence of 'm'
        int index = name.find('@');
        int indexLastM = name.find_last_of('m');

        if (index != std::string::npos && indexLastM != std::string::npos) {
            name.erase(index, indexLastM - index + 1); // Remove from '@' to 'm' inclusive
        }

        std::cout << "\nYour twitter username is: @" << name;
    }
    std::cout << "\n-------------------------------------------------------------------------------------- \n";
    return 0;
}
