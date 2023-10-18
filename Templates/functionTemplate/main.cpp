#include <iostream>
using namespace std;
/*
C++ has long supported overloaded functions, but these can be tedius and error-prone to write, especially if the
Logic is the same, but only the types differ.
*/
int plus(int a, int b)
{
    return a + b;
}
long plus(long a, long b)
{
    return a +b;
}
double plus(double a, double b)
{
    return a + b;
}
/*
Function templates are special functions that can operate on different data types without separate code for each
of them. For a similar operation on several kinds of data types, therefore, it isn't always as efficient to write
several different versions by overloading a function; write one template function will take care of many cases
where overloaded functions might be written. Thus, this template member generalizes all the overloaded 
"plus()" methods above.
*/
template <typename T, typename U, typename V>
T add(T a, U b, V c)
{
    return a + b + c;
}
/*
In the case of add() where only one generic type T is used as a parameter for add(), the compiler can automatically
determine which data type to instantiate the function for without having to explicitly specify the datatype within
angle brackets (Like we have done before specifying <int> and <long>). This selection process is called 
"argment deduction".
*/
int main()
{
    int i = 5, j = 6, k;
    long l = 10, m = 5,n;
    double d= 5.76, e = 9.3, f;
    double d = add(i, d, l);
    cout << d << endl;

    return 0;
}