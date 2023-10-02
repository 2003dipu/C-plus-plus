
// foreach(){loop} = loop that eases the traversal over an iterable data set.

#include <iostream>

int main()
{
    std::cout << "\n-----------------------------------------------------------------------------\n";
    std::string friendNames[] = {"Amit Singha", "Shrabanto Singha", "Pronoy Singha", "Tusar Singha", "Shimul Singha"};
    int grades[] = {1, 2, 3, 4, 5};
    for (std::string friendName : friendNames)
    {
        std::cout << friendName << "  ";
    }
    std::cout << "\n";
    for (int grade : grades)
    {
        std::cout << "  | " << grade << " |        ";
    }

    std::cout << "\n-----------------------------------------------------------------------------\n";
    return 0;
}
