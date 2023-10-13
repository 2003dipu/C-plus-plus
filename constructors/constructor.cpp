/* what are constructors? = Constructors (C++)
Article • 02/08/2022
To customize how a class initializes its members, or to invoke functions when an object
of your class is created, define a constructor. A constructor has the same name as the
class and no return value. You can define as many overloaded constructors as needed to
customize initialization in various ways. Typically, constructors have public accessibility
so that code outside the class definition or inheritance hierarchy can create objects of
the class. But you can also declare a constructor as protected or private .
*/

// Example=================== 2
/*
#include <iostream>
using namespace std;
class Box
{
public:
    int Volume() // constructor
    {
        m_weight = 5; // reassigning the value
        m_height = 4;
        m_length = 3;
        // perform any required default initialization steps
        return m_weight * m_height * m_length;
    }
    private :
    int m_weight {0};
    int m_height {0};
    int m_length {0};
};

int main()
{
    cout << "\n\n==============================================================================\n\n";
    Box box1;  // Invoke compiler-generated constructor
    double vol_Box = box1.Volume();
    cout << "box1.volume:\t" << vol_Box << endl;


    cout << "\n\n==============================================================================\n\n";
}
*/
// Example=================== 2
#include <iostream>
using namespace std;

class Car // a class named Car
{
    // private data members
private:
    string brand; // the brand of the car
    string model; // the model of the car
    int year;     // the year of manufacture

    // public data members
public:
    // a default constructor that sets default values
    Car()
    {
        brand = "unknown";
        model = "unknown";
        year = 2023;
    }
    // a parameterized constructor that sets values according to arguments
    Car(string b, string m, int y)
    {
        brand = b;
        model = m;
        year = y;
    }
    // a function(method because inside a class) to display the details of the car
    void display()
    {
        cout << "\tBrand:\t" << brand << endl;
        cout << "\tModel:\t" << model << endl;
        cout << "\tYear :\t" << year << endl;
    }
};

int main()
{
    cout << "\n\n==============================================================================\n\n";
    // creating two objects of Car class using different constructors
    Car c1; // using default constructor

    // taking user input to fill in the parameter in the parameterized constructor
    cout << "What's the car's Brand?:\t";
    string brand;
    getline(cin, brand);
    cout << "What's the car's model?:\t";
    string model;
    getline(cin, model);
    cout << "What's the year of car's manufacture?:\t";
    int year;
    cin >> year;

    Car c2(brand, model, year); // using parameterized constructor

    // displaying the details of both objects
    cout << "\t\t < Details of car 1 > \n";
    c1.display();
    cout << "\t\t < Details of car 2 > \n";
    c2.display();

    cout << "\n\n==============================================================================\n\n";
    return 0;
} // within 63 lines of code



