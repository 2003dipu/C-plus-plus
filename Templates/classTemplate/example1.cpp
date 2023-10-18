#include <iostream>
using namespace std;

template<typename T, typename U>
auto findMax(T x, U y)
{
    return (x > y) ? x : y;
}
int main()
{
    cout << "\n\nThe maximum is:\n";
    cout << findMax(5.1, 2.54) << endl;
    cout << findMax(22.67, 11) << endl;
    cout << findMax('a', 'A') << endl;
    cout << findMax('E', 'C') << endl;

    return 0;
}