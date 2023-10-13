
#include <iostream>
using namespace std;

class Pizza
{
public:
    string topping1;
    string topping2;

    Pizza()
    {

    }

    Pizza(string topping1)
    {
        this->topping1 = topping1;
    }

    Pizza(string topping1, string topping2)
    {
        this->topping1 = topping1;
        this->topping2 = topping2;
    }
};

int main()
{
    cout << "\n\n======================================================================\n\n";
    Pizza pizza1("Pepperoni1");
    Pizza pizza2("Mushrooms", "Peppers");
    Pizza pizza3;

    cout << pizza2.topping1 << "\n";
    cout << pizza2.topping2 << "\n";

    cout << "\n\n======================================================================\n\n";
    return 0;
}