// what are classs and objects in C++ or other programming languages?
// Object =  A collection of attributes and methods. They can have characteristic and could perform actions
// can be used to mimic real worlds items (ex. Phone, Book, Dog, School, House, Foods)
// Created from a class which acts as a "blue-print"
// Methods = A method is a function that belongs to a class. It's something that an object can do, an action it can
// perform. What sorts of actions should arguments be able to perform?


// private specifier :data types declared inside the scope of access specifier of private are only accessible inside 
//the method of that class.


/*

// Example ==================1
#include <iostream>
using namespace std;

class Human
{
    public :
    string name;
    int age;
    double height = 5.7;
    double weight = 60.5;
    string occupation;
    string language = "English & Bishnupriya Monipuri";

    void eat()
    {
        cout << "This person can eat.\n";
    }
    void learn()
    {
        cout << "This person can learn anything.\n";
    }
    void sleep()
    {
        cout << "This person needs 8 hours sleep every night.\n";
    }
    void drink()
    {
        cout << "This person can drink milk, water and coconut water\n";
    }
    auto doSomething(double num1, double num2)
    {
        auto result = num1 + num2;
        return result;
    }
    auto calculation()
    {
        cout << "\n==============================================================================" << endl;
        cout << "\t\tAdd any two numbers\n";
        double a;
        cout << "Enter num1:\t";
        cin >> a;
        double b;
        cout << "Enter num2:\t";
        cin >> b;
        cout << endl;

        cout << a << " + " << b << " =\t" << doSomething(a,b);
    }
    string writeSomething()
    {
        string strSome =  "This person can write anything. Printed from \"string\" method writeSomething() \n";
        //cout << strSome;
        return strSome;
    }

};

int main()
{
    cout << endl << endl;

    Human human1; // human1 is an object an is also an unique identifier
    human1.name = "Dipu Singha";
    human1.occupation = "Scientist";
    human1.age = 21;

    cout << human1.writeSomething();

    Human human2;
    human2.name = "Huna Bopa";
    human2.age = 121;
    human2.occupation = "Teacher";
    cout << "Human2\t\tAttributes and characteristic\n";
    cout << "Name:\t\t" << human2.name << endl;
    cout << "Occupation:\t" << human2.occupation << "\n";
    cout << "Age:\t\t" << human2.age << endl;
    cout << "Weight:\t\t" << human2.weight << endl;
    cout << "Height:\t\t" << human2.height << endl;

    human2.eat();
    human2.sleep();
    Human calculate;

    calculate.calculation();

    cout << "\n==============================================================================" << endl;
    cout << "\n\n";
    return 0;
}
*/

/*
// Example ==================2
#include <iostream>
using namespace std;
class Car
{
private:
    // data
public:
    string make;
    string model;
    int year;
    string color;
    // methods
    void accelerate()
    {
        cout << "You step on the gas.\n";
    }
    void brake()
    {
        cout << "You step on the brake";
    }

}; // Car class ends here


int main()
{
    cout << "\n=============================================================================================\n";
    Car car1; // car1 is an unique identifier for the Car object

    car1.make = "Ford";
    car1.model = "Mustang";
    car1.year = 2023;
    car1.color = "silver";

    cout << "car1 make\t\t" << car1.make << "\n";
    cout << "car1 model\t\t" << car1.model << "\n";
    cout << "car1 year\t\t" << car1.year<< "\n";
    cout << "car1 color\t\t" << car1.color << "\n";

    car1.accelerate();
    car1.brake();


    cout << "\n=============================================================================================\n";
    return 0;
}
*/

/*
#include <iostream>
using namespace std;
// A simple class with private and public members
class Rectangle {
  private:
    // Private members are only accessible within the class
    int length;
    int width;
  public:
    // Public members are accessible outside the class
    // A constructor to initialize the length and width
    Rectangle(int l, int w) {
      length = l;
      width = w;
    }
    // A method to calculate the area of the rectangle
    int area() {
      return length * width;
    }
};

// A main function to test the class
int main() {
  // Create an object of Rectangle class with length 10 and width 5
  Rectangle r(10, 5);
  // Print the area of the rectangle using the public method
  cout << "The area of the rectangle is " << r.area() << endl;
  return 0;
}
*/
// Example ==================3
// A simple Animal class with private and public members

#include <iostream>
using namespace std;

class Animal {
  private:
    // Private members are only accessible within the class
    string name = "Dog"; // The name of the animal
    string color; // The color of the animal
    string sound; // The sound of the animal
    string CheckAccesOutside;
  public:

    string nightwatch;
    // CheckAccessOutside's access outside any method denied
    
    // Public members are accessible outside the class
    // A constructor to initialize the name, color, and sound
    auto features(string n, string c, string s) {
      name = n;
      color = c;
      sound = s;
      cout << "Name:\t" << name << "\n";
      cout << "Color:\t" << color << "\n";
      cout << "Sound:\t" << sound << "\n";
      CheckAccesOutside = "Access in a function allowed";
    }
    // A method to make the animal eat
    void eat() {
      cout << name << " is eating" << endl;
      CheckAccesOutside = "Access in another method allowed";
    }
    // A method to make the animal sleep
    void sleep() {
      cout << name << " is sleeping" << endl;
    }
    // A method to make the animal make noise
    void makeNoise() {
      cout << name << " says " << sound << endl;
    }
    
};

int main()
{
    cout << "\n\n================================================================================\n\n";

    Animal prani;
    prani.eat();
    auto p = prani.nightwatch = "Bark all the night";
    cout << p;
    string name, color, sound ;
    name = "Dog";
    color = "Brown";
    sound = "Gauu Gauu";
    prani.features(name, color, sound);
    cout << p;


    cout << "\n\n================================================================================\n";
    return 0;
}
