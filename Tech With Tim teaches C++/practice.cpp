#include <iostream>
using namespace std;

// #define NAME_SIZE 50 ( defines a macro  C-style)

constexpr int NAME_SIZE = 10; // modern C++

class Person
{
    int id; // all members are private by default
    char name[NAME_SIZE];

    public:
        void aboutMe()
        {
            cout << "I am a person.\n";
        }
};

class Student : public Person
{
    public:
    void aboutMe()
    {
        cout << "I am a student.\n";
    }
};

int main()
{
    Student * p = new Student(); // old fashioned
    p->aboutMe(); // prints "I am a Student."
    // new system or method. Modern C++ convention you name it,right?
    Person person;
    person.aboutMe();
    // or (using pointer * and arrow ->)
    Person * person1;
    person1->aboutMe();
    delete p; // important! Make sure to delete allocated memory.
    return 0;
}