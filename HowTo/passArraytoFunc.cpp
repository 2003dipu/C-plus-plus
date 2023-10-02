
// How to pass arrays to functions?

#include <iostream>

double getTotal(double prices[], int sizeA)
{
    double total = 0;
    for (int i = 0; i < sizeA; i++)
    {
        total += prices[i];
    }
    return total;
}

int main()
{
    double prices[] = {140.55, 80.34, 60.84, 70.5, 50};
    int sizeA = sizeof(prices) / sizeof(prices[1]);
    double total = getTotal(prices, sizeA);

    std::cout << "Total: $ " << total;

    return 0;
}

