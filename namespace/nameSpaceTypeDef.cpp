#include<iostream>
/*
A namespace in C++ is a way of grouping related symbols together to avoid name conflicts in large projects. 
A namespace can contain variables, functions, classes, and other namespaces. You can define a namespace using 
the keyword `namespace` followed by the name of the namespace and a block of code that contains the declarations 
of the symbols. For example:

namespace ContosoDataServer {
    void Foo();
    int Bar();
}

This defines a namespace called `ContosoDataServer` that contains two symbols: a function named `Foo` and a 
variable named `Bar`. To access these symbols from outside the namespace, you need to use the scope resolution 
operator `::` and prefix the symbol name with the namespace name. For example:

ContosoDataServer::Foo(); // calls the function Foo in the ContosoDataServer namespace
int x = ContosoDataServer::Bar; // assigns the value of Bar to x

You can also use the `using` directive to introduce the symbols from a namespace into the current scope, so that 
you don't have to use the scope resolution operator every time. For example:

using namespace ContosoDataServer; // makes all symbols from ContosoDataServer available in this scope
Foo(); // calls the function Foo without prefixing the namespace name
int y = Bar; // assigns the value of Bar to y

However, using this directive can cause name conflicts if there are symbols with the same name in different 
namespaces or in the global scope. To avoid this, you can use the `using` declaration to introduce only specific 
symbols from a namespace into the current scope. For example:

using ContosoDataServer::Foo; // makes only Foo available in this scope
Foo(); // calls Foo without prefixing the namespace name
int z = ContosoDataServer::Bar; // still need to prefix Bar with the namespace name

Namespaces can also be nested, meaning that you can define one namespace inside another. To access the symbols 
from a nested namespace, you need to use multiple scope resolution operators to specify the full path of the 
symbol. For example:

namespace Outer {
    namespace Inner {
        void Baz();
    }
}

Outer::Inner::Baz(); // calls Baz from the Inner namespace inside the Outer namespace


You can also use an alias to give a shorter or more descriptive name to a namespace or a nested namespace. For 
example:


namespace OI = Outer::Inner; // creates an alias for Outer::Inner
OI::Baz(); // calls Baz using the alias


Namespaces are useful for organizing your code and avoiding name clashes with other libraries or modules.


namespace first{
    int a = -1;
}
namespace second{
    int a = -2;
}
int main(){

    //int a = -3;
    //std::cout << "third  " << a << "\n";
    std::cout << "second " << second::a << "\n";
    //std::cout << "first  " << first::a << "\n";
    using namespace first;
    std::cout << "Alternative: using directive:" << a;
    // comments
    return 0;
}

// save a little bit of typing

int main(){
    using namespace std;
    string name = "Dipu Singha";
    cout << "Hello " << name;


    return 0;
}

*/

/* Typedefs and type aliases
   typedef = reserved keyword used to create an additional name
                      (alias) for another data type.
                      New identifier for an existing type
                      Helps with readability and reduces typos
                      Use when there is a clear benefit
                      Replaced with 'using' (work better w/ templates)*/
#include<vector>

//typedef std::vector<std::pair<std::string, int>> pairlist_t;
//typedef std::string text_t;
//typedef int number_t;
using text_t = std::string;
using number_t = int;

int main(){

    //pairlist_t pairlist;
    text_t name = "Bro Code(Chris)";
    number_t myNum = 123;
    std::cout << myNum << "\n";
    std::cout << name << "\n";

    return 0;
}