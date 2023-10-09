// structs? = A structure that groups related variables under one name. structs can contain many different data 
//types (string, int, double, bool, etc.)
// variables in a struct are known as "members". members can be accessed with . "Class Member Access Operator"
#include <iostream>

struct Student
{
    std::string name;
    int serialNumber;
    bool enrolled = true;

};

int main()
{   
    std::cout << "\n\t\n";

    Student student1; 
    std::cout << "What is your name?\t: ";
    std::getline(std::cin, student1.name);
    std::cout << "What's your serialNumber: ";
    std::cin >> student1.serialNumber;
   
    Student student2; 
    student2.name = "Mike Dane";
    student2.serialNumber = 2;
    
    Student student3; 
    student3.name = "Bro Code";
    student3.serialNumber = 3;
    
    std::cout << "\n\n\tStudent Name\t" << student1.name << "\n";
    std::cout << "\tSerial Number\t" << student1.serialNumber << "\n";
    std::cout << "\tEnrolled\t" << student1.enrolled << " = Yes\n\n";

    std::cout << "\tStudent Name\t" << student2.name << "\n";
    std::cout << "\tSerial Number\t" << student2.serialNumber << "\n";
    std::cout << "\tEnrolled\t" << student2.enrolled << " = Yes\n\n";

    std::cout << "\tStudent Name\t" << student3.name << "\n";
    std::cout << "\tSerial Number\t" << student3.serialNumber << "\n";
    std::cout << "\tEnrolled\t" << student3.enrolled << " = Yes\n\n";

    std::cout << "\n\t\n";
    return 0;
}