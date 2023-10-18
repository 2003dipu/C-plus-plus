#include <iostream>
using namespace std;

template <typename T, typename U>
auto swapNumbers(T x, U y)
{
    x = y;
    y = x;
}
void manageUserInput()
{
    double x;
    cout << "Enter a number to swap: x = ";
    cin >> x;
    double y;
    cout << "Enter another number to be swapped with: y = ";
    cin >> y;
    cout << "\n\nInitially x = " << x << " and y = " << y << " however after swapping :><: ";
    swap(x, y);
    cout << "\n\tx = " << x << " and \n\ty = " << y << endl;
}

int main()
{
    cout << "\n\n=================================================================================\n";

    manageUserInput();

    cout << "\n\n=================================================================================\n";

    return 0;
}