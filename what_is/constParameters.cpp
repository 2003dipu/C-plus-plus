/* what are const parameters? = In C++, "const parameters" typically refer to function parameters that are declared
as const. When aparameter is declared as const, it means that the function promises not to modify the value of 
that parameter within the scope of the function. This is a form of indicating to both the compiler and other 
programmers that the function won't change the value of the parameter. It's a readonly
*/

/*
#include <iostream>
using namespace std;


void printValue(const int x) {
    // This function cannot modify the value of 'x'.
    // It can only read 'x'.
    cout << x << endl;
}
int main()
{
    int fFunc = 24;
    printValue(fFunc);
}
*/
/*
#include <iostream>

// Define a simple class
class MyClass {
public:
    void sayHello() {
        std::cout << "Hello from MyClass!" << std::endl;
    }
    std::string stpS()
    {
        std::string print = "This is returned from the stpS function > ";
        int num = 5;
        std::cout << print << num;

        return print;
    }
};

int main() {
    // Create an instance of MyClass
    MyClass singha;
    // Call a method of the class
    singha.sayHello();
    singha.stpS();

    return 0;
}
*/

#include <iostream>

void printInfo(const std::string name, const int age)
{
    std::cout << "Hello " << name << ".\nYou are " << age << " years old";
}

int main()
{
    int age = 21;
    std::string name = "Bro Code";
    printInfo(name, age);

    return 0;
}