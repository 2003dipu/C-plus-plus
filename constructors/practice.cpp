/*

=====================================================================================================================

A constructor in C++ is a special type of member function that is called automatically when an object of a class is
created. It is used to initialize the data members of the object with some initial values. A constructor has the
same name as the class and does not have any return type. For example, if you have a class named Car, then the
constructor of that class will be Car(). You can also pass parameters to the constructor to set the values of the
data members according to the arguments. For example, Car(string brand, string model, int year) will create a Car
object with the given brand, model and year values. You can define a constructor either inside or outside the class
declaration, but it must be public.

Here is an example code that shows how to define and use constructors in C++:


// A class named Car
class Car {
  // Private data members
  private:
    string brand; // The brand of the car
    string model; // The model of the car
    int year; // The year of manufacture

  // Public member functions
  public:
    // A default constructor that sets default values
    Car() {
      brand = "Unknown";
      model = "Unknown";
      year = 0;
    }

    // A parameterized constructor that sets values according to arguments
    Car(string b, string m, int y) {
      brand = b;
      model = m;
      year = y;
    }

    // A function to display the details of the car
    void display() {
      cout << "Brand: " << brand << endl;
      cout << "Model: " << model << endl;
      cout << "Year: " << year << endl;
    }
};

// The main function
int main() {
  // Creating two objects of Car class using different constructors
  Car c1; // Using default constructor
  Car c2("Toyota", "Corolla", 2023); // Using parameterized constructor

  // Displaying the details of both objects
  cout << "Details of car 1:" << endl;
  c1.display();
  cout << "Details of car 2:" << endl;
  c2.display();

  return 0;
}

The output of this code will be:

Details of car 1:
Brand: Unknown
Model: Unknown
Year: 0
Details of car 2:
Brand: Toyota
Model: Corolla
Year: 2023

I hope this example helps you understand constructors in C++. If you want to learn more, read documentation,
online article, or ask ChatGPT, Bard and Bing

*/
/*
Move constructors

A move constructor is a special member function that moves ownership of an existing
object's data to a new variable without copying the original data. It takes an rvalue
reference as its first parameter, and any later parameters must have default values.
Move constructors can significantly increase your program's efficiency when passing
around large objects

*/
// example code ====================================================================

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Box
{
public:
    Box() { std::cout << "default" << std::endl; }
    Box(int width, int height, int length)
        : m_width(width), m_height(height), m_length(length)
    {
        std::cout << "int,int,int" << std::endl;
    }
    Box(Box &other)
        : m_width(other.m_width), m_height(other.m_height),
          m_length(other.m_length)
    {
        std::cout << "copy" << std::endl;
    }
    Box(Box &&other) : m_width(other.m_width), m_height(other.m_height),
                       m_length(other.m_length)
    {
        m_contents = std::move(other.m_contents);
        std::cout << "move" << std::endl;
    }
    int Volume() { return m_width * m_height * m_length; }
    void Add_Item(string item) { m_contents.push_back(item); }
    void Print_Contents()
    {
        for (const auto &item : m_contents)
        {
            cout << item << " ";
        }
    }

private:
    int m_width{0};
    int m_height{0};
    int m_length{0};
    vector<string> m_contents;
};
Box get_Box()
{
    Box b(5, 10, 18); // "int,int,int"
    b.Add_Item("Toupee");
    b.Add_Item("Megaphone");
    b.Add_Item("Suit");
    return b;
}
int main()
{
    Box b;             // "default"
    Box b1(b);         // "copy"
    Box b2(get_Box()); // "move"
    cout << "b2 contents: ";
    b2.Print_Contents(); // Prove that we have all the values

    char ch;
    cin >> ch; // keep window open
    return 0;
}
