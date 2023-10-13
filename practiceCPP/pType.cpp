// command_line_arguments.cpp
// compile with: /EHsc
// This code is fascinating. It prints out my current file location
/*
#include <iostream>
using namespace std;

int main(int argc,     // Number of strings in array argv
         char *argv[], // Array of command-line argument strings
         char *envp[]) // Array of environment variable strings
{
    cout << "\n====================================================================\n";
    int count;
    // Display each command-line argument.
    cout << "\nCommand-line arguments:\n";
    for (count = 0; count < argc; count++)
        cout << " argv[" << count << "] "
             << argv[count] << "\n";

    cout << "\n====================================================================\n";
}
*/

/*
// Shows the actual memory layout
struct x_
{
 char a; // 1 byte
 char _pad0[3]; // padding to put 'b' on 4-byte boundary
 int b; // 4 bytes
 short c; // 2 bytes
 char d; // 1 byte
 char _pad1[1]; // padding to make sizeof(x_) multiple of 4
} bar[3];

adr offset element
------ -------
0x0000 char a; // bar[0]
0x0001 char pad0[3];
0x0004 int b;
0x0008 short c;
0x000a char d;
0x000b char _pad1[1];
0x000c char a; // bar[1]
0x000d char _pad0[3];
0x0010 int b;
0x0014 short c;
0x0016 char d;
0x0017 char _pad1[1];
0x0018 char a; // bar[2]
0x0019 char _pad0[3];
0x001c int b;
0x0020 short c;
0x0022 char d;
0x0023 char _pad1[1];


*/

/*
// alignas_alignof.cpp
// compile with: cl /EHsc alignas_alignof.cpp
#include <iostream>
struct alignas(16) Bar
{
 int i; // 4 bytes
 int n; // 4 bytes
 alignas(4) char arr[3];
 short s; // 2 bytes
};
int main()
{
 std::cout << alignof(Bar) << std::endl; // output: 16
}

*/

/*
#include <type_traits>
#include <iostream>
using namespace std;
struct B
{
protected:
 virtual void Foo() {}
};
// Neither trivial nor standard-layout
struct A : B
{
 int a;
 int b;
 void Foo() override {} // Virtual function
};
// Trivial but not standard-layout
struct C
{
A literal type is one whose layout can be determined at compile time. The following are
the literal types:
void
scalar types
references
Arrays of void, scalar types or references
 int a;
private:
 int b; // Different access control
};
// Standard-layout but not trivial
struct D
{
int a;
 int b;
 D() {} //User-defined constructor
};
struct POD
{
 int a;
 int b;
};
int main()
{
 cout << boolalpha;
 cout << "A is trivial is " << is_trivial<A>() << endl; // false
 cout << "A is standard-layout is " << is_standard_layout<A>() << endl;
// false
 cout << "C is trivial is " << is_trivial<C>() << endl; // true
 cout << "C is standard-layout is " << is_standard_layout<C>() << endl;
// false
 cout << "D is trivial is " << is_trivial<D>() << endl; // false
 cout << "D is standard-layout is " << is_standard_layout<D>() << endl; //true
 cout << "POD is trivial is " << is_trivial<POD>() << endl; // true
 cout << "POD is standard-layout is " << is_standard_layout<POD>() <<
endl; // true
 return 0;
}
*/

/*

// C2039 expected
class A
{
public:
 int AComponent;
 int AMemberFunc();
};
class B : public A
{
public:
 int BComponent;
 int BMemberFunc();
};
int main()
{
 B bObject;
 A *pA = &bObject;
 B *pB = &bObject;
 pA->AMemberFunc(); // OK in class A
 pB->AMemberFunc(); // OK: inherited from class A
 //pA->BMemberFunc(); // Error: not in class A
} */

#include <iostream>
using namespace std;
class Box
{
public:
    // Default constructor
    Box() {}
    // Initialize a Box with equal dimensions (i.e. a cube)
    explicit Box(int i) : m_width(i), m_length(i), m_height(i) // member init list
    {
    }
    // Initialize a Box with custom dimensions
    Box(int width, int length, int height)
        : m_width(width), m_length(length), m_height(height)
    {
        cout << "This line is printed from the Box(int width, int length, int height) method\n";
    }
    int Volume(string calculate)
    {
        cout << calculate;
        return m_width * m_length * m_height;
    }

private:
    // Will have value of 0 when default constructor is called.
    // If we didn't zero-init here, default constructor would
    // leave them uninitialized with garbage values.
    int m_width = 0;
    int m_length = 1;
    int m_height = 2;
};

int main()
{
    cout << "\n\n======================================================================\n\n";

    Box b; // Calls Box()
    // Using uniform initialization (preferred):
    Box b2{5};        // Calls Box(int)
    Box b3{5, 8, 12}; // Calls Box(int, int, int)
    // Using function-style notation:
    Box b4(2, 4, 6); // Calls Box(int, int, int)
    string calculate = "Volume:\t";
    cout << b3.Volume(calculate);

    cout << "\n\n======================================================================\n\n";
}
