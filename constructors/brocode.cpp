
// constructor = A constructor is a special method that is automatically called when an oject is instantiated
// useful for assigning values to attributes as arguments.
/*
// example 1
#include <iostream>

using namespace std;

class student
{
    // public access modifier
public:
    string name;
    int age;
    double gpa;

    student(string x, int y, double z)
    {
        name = x;
        age = y;
        gpa = z;
    }

    void display()
    {
        cout << "\t" << name << endl;
        cout << "\t" << age << endl;
        cout << "\t" << gpa << endl;
    }
};

int main()
{
    cout << "\n\n=====================================================================================\n\n";

    student stu1("Shimul", 25, 3.2);
    student stu2("Patrick", 30, 4.5);
    student stu3("Sandy", 20, 4.0);

    stu1.display();
    stu2.display();
    stu3.display();

    cout << "\n\n=====================================================================================\n\n";

    return 0;
}
*/

// the following example will teach you thoroughly about constructor
// example 2
/*
#include <iostream>
using namespace std;

class contained1
{
    public:
    contained1(){cout << "\t\tcontained1 constructor\n";}
};
class contained2
{
    public:
    contained2(){cout << "\t\tcontained2 constructor\n";}
};
class contained3
{
    public:
    contained3(){cout << "\t\tcontained3 constructor\n";}
};
class BaseContainer
{
    public:
    BaseContainer(){cout << "\t\tBaseContainer constructor\n";}

    private:
    contained1 c1;
    contained2 c2;

};
class DerivedContainer: public BaseContainer
{
    public:
    DerivedContainer() : BaseContainer(){cout << "\t\tDerivedContainer constructor\n";}

    private:
    contained3 c3;

};

int main()
{
    cout << "\n=====================================================================================\n\n";
    DerivedContainer dc;
    cout << "\n=====================================================================================\n";
}
*/
// example ============= 3 (constructor very simplified even a child can understand it)

#include <iostream>
using namespace std;

class Car
{
    public:
        string make;
        string model;
        int year;
        string color;

    Car(string make, string model, int year, string color)
    {
        this -> make = make;
        this -> model = model;
        this -> year = year;
        this -> color = color;
    }
};

int main()
{
    cout << "\n\n=====================================================================================\n\n";

    Car car1("Chevy", "Corvette", 2022, "blue");

    cout << car1.make << endl;
    cout << car1.model << endl;
    cout << car1.year << endl;
    cout << car1.color << endl << endl;

    Car car2("Ford", "Mustang", 2022, "silver");

    cout << car2.make << endl;
    cout << car2.model << endl;
    cout << car2.year << endl;
    cout << car2.color << endl;

    cout << "\n\n=====================================================================================\n\n";
    return 0;
}