/*
#include <iostream>

using namespace std;

// what is a function? = simply put: is a program to automate tasks

int add(int x, int y) // call it parameterized function
{
    return x + y;
}

int getNumber() // call it non-parameterized function
{
    return 6;
}

void test()
{
    for (int i = 0; i < 100; i++) // it took 25 seconds to print out 1 through 100000
    {
        cout << i << endl;
    }
}

void printNtimes(int n, string text)
{
    for (int i = 0; i < n; i++)
    {
        if (i == n / 2)
        {
            cout << text << " -> crossed half way" << endl;
            //continue;
        }
        else
        {
            cout << i + 1 << ": " << text << endl;
        }
    }
}

int main()
{
    // int result = add(2,3);
    // cout << result << endl;
    // cout << getNumber() << endl;
    // test();
    printNtimes(6, "I love you");
    // printNtimes(5, "Dipu Singha");

    return 0;
}
*/
/*
#include <iostream>
using namespace std;

void print(string text)
{
    cout << text << endl;
}
void printNtimes(int n, string text)
{
    for (int i = 0; i < n; i++)
    {
        print(text);
    }
}
// default parameters
int doMath(int x, int y, int z = 1)
{
    return (x + y) * z;
}

int main ()
{
    double result = doMath(2, 3);
    cout << result << endl;

    return 0;
}
*/
