// alg_for_each_n.cpp
// compile with /EHsc and /std:c++17 (or higher)
#include <algorithm>
#include <iostream>
#include <vector>

// The function object multiplies an element by a Factor

template <class Type>
class MultValue
{
private:
    Type Factor; // The value to multiply each element by
public:
    // Constructor initializes the value to multiply by

    MultValue(const Type &value) : Factor(value) {}

    // The function call for the element to be multiplied

    void operator()(Type &elem) const
    {
        elem *= Factor;
    }
};

// Utility to display the contents of a vector
template <class T>
void print_vector(const std::vector<T> &vec)
{

    std::cout << "( ";
    for (auto iter = vec.begin(); iter != vec.end(); iter++)
    {
        std::cout << *iter << ' ';
    }
    std::cout << ").\n";
}

int main()
{
    std::vector<int> v;
    // Construct vector with the elements -4...2
    for (int i = -4; i <= 2; i++)
    {
        v.push_back(i);
    }
    std::cout << "Original vector v = ";
    print_vector(v);

    // Use for_each_n to multiply the first 3 elements by a Factor,
    // saving the position in the vector after the first 3 elements

    auto pos = for_each_n(v.begin(), 3, MultValue<int>(-2));
    std::cout << "Multiplying the first 3 elements of the vector v\n "
              << "by the factor -2 gives:\n vmod1 = ";
    print_vector(v);

    // Using for_each_n to multiply the next 4 elements by a Factor,
    // starting at the position saved by the previous for_each_n

    for_each_n(pos, 4, MultValue<int>(-3));
    std::cout << "Multiplying the next 4 elements of the vector v\n "
              << "by the factor -3 gives:\n vmod2 = ";
    print_vector(v);
    return 0;
}