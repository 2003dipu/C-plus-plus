// what are function template? = describes what a function looks like. Can be used to generate as many overloaded
// functions as needed, each using different data types.
/*
// -----------------------------------------project return the maximum number
#include <iostream>

int max(int x, int y)
{
    return (x > y) ? x : y;
}
double max(double x, double y)
{
    return (x > y) ? x : y;
}
char max(char x, char y)
{
    return (x > y) ? x : y;
}
int main()
{
    std::cout << "\n\t\t<< Project name: Function template(Overloaded function) >>\n";

    int x = 13.23;
    int y = 34.55;
    std::cout << "\t\t" << max('C', 'B') << "\n";

    std::cout << "\n\t\n";
    return 0;
}
*/
/*
// -----------------------------------------project function template
#include <iostream>

template <typename T>

T max(T x, T y)
{
    return (x > y) ? x : y;
}
int main()
{
    std::cout << "\n\t\t<< Project name: Function template(Overloaded function) >>\n";

    double x = 13.23;
    double y = 34.55;
    std::cout << "\t\t" << max(x,y) << "\n";

    std::cout << "\n\t\n";
    return 0;
}
*/

// -----------------------------------------project multiple function template
// write a function once, then it's compatible with different data types = that's function template. With auto keyword the function
// return type is automatically detedted or deduced by the compiler
/*
#include <iostream>

template <typename T, typename U>

auto max(T x, U y)
{
    return (x > y) ? x : y;
}
int main()
{
    std::cout << "\n\t\t<< Project name: Multiple Function template(Overloaded function) + auto keyword >>\n";

    double x = 13.23;
    double y = 34.55;
    std::cout << "\t\t" << max(x,10) << "\n";

    std::cout << "\n\t\n";
    return 0;
}
*/
#include <iostream>

template <typename T>

T add(T a, T b)
{
    return a + b;
}

int main()
{
    std::cout << "\n\t\t<< Project name: Division + auto keyword >>\n";
    double num1 = 2.5;
    double num2 = 10;
    std::cout << "Added:\t" << add(num1, num2);

    std::cout << "\n\t\n";
    return 0;
}