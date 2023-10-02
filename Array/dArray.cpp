
// what are arrays? = a data structure that can hold multiple values
//                  values are accessed by an index number
// kind of like a variable that can hold multiple values
/*
#include <iostream>

int main()
{
    //std::string cars[] = {"Corvette", "Mustang", "Camry"};// declare an array and assign value to it. No length specification required
    std::string cars[5];
    cars[0] = "Dipu";
    cars[1] = "Singha";
    cars[2] = "Anushka";
    cars[3] = "Rosmi";
    cars[4] = "Sinha";
    std::cout << cars[2];
    double prices[] = {23.45, 234.53, 26.6, 60.06, 45.93};
    std::cout << prices[4];


    return 0;
}
*/
// sizeof() operator = determine the size in bytes of a variable, data type, class, objects, etc.
/*
#include <iostream>

int main()
{
    // size of a string = 32 bytes
    // size of a string array = 32 * n (n = number of elements inside of the array) and vice versa
    std::cout << "\n-------------------------------------------------------------------------------\n";
    std::string name = "Dipu Singha and I love someone 123!";
    double gpa = 3.75;
    char grades[] = {'A', 'B', 'C', 'D', 'F'};
    double marks[] = {13.5, 4.55, 5.66, 65.45, 34.65};
    int numbers[] = {6,7,8,9,10};
    std::string partnerNames[] = {"Dipu Singha", "Anushka Sinha", "Rosmi Sinha", "Unknown", "Hannai"};
    //std::cout << sizeof(gpa) << " bytes\n";
    //std::cout << sizeof(name) << " bytes\n";
    std::cout << "size of a char        = " << sizeof(char) << " bytes\n";
    std::cout << "size of a bool        = " <<  sizeof(bool) << " bytes\n";
    std::cout << "size of an int        = " << sizeof(int) << " bytes\n";
    std::cout << "size of char array    = " <<  sizeof(grades) << " bytes\n";
    std::cout << "size of a double      = " <<  sizeof(double) << " bytes\n";
    std::cout << "size of a string      = " << sizeof(std::string) << " bytes\n";
    std::cout << "size of int array     = " <<  sizeof(numbers) << " bytes\n";
    std::cout << "size of double array  = " <<  sizeof(marks) << " bytes\n";
    std::cout << "size of string array  = " <<  sizeof(partnerNames) << " bytes\n";
    double elements = sizeof(partnerNames);
    std::cout << elements << "\n";
    std::cout << "However, Size of an array depends on the numbes of elements inside of the array";


    std::cout << "\n-------------------------------------------------------------------------------\n";
    return 0;
}
*/

// how to iterate over an array?
/*
#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> students = {"Rosmi Sinha", "Anushka Sinha", "Shorbani Sinha", "Hannai Sinha", "Mihan_napasu Sinha", "Harpasu"};
    std::size_t stu_length = students.size(); // Use std::size_t for size and indices
    for (std::size_t i = 0; i < stu_length; i++)
    {
        std::cout << students[i] << "\n";
    }

    return 0;
}
*/

// alternative to the above code

#include <iostream>

int main()
{
    std::string students[] = {"Rosmi Sinha", "Anushka Sinha", "Shorbani Sinha",
     "Hannai Sinha"};
    char grades[] = {'A','B','C','F'};
    int numElemnts = sizeof(students) / sizeof(std::string);
    for (int i = 0; i < numElemnts; i++) // number of elements are automated. No manual spefication required any more
    {
        std::cout << students[i] << ":    ";
        std::cout << grades[i] << "\n";
    }

    return 0;
}