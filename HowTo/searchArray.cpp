
// How to search an array for an element?
/*
// Example -----------------------------------------------1
#include <iostream>

int searchArray(int array[], int size_of_Array, int element)
{
    for (int i = 0; i < size_of_Array; i++)
    {
        if(array[i] == element)
        {
            return i;
        }
    }
    return -1;

    return 0;
}

int main()
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int size_of_Array = sizeof(numbers) / sizeof(numbers[0]) ;
    int index;
    int myNum;
    std::cout << "Enter element to search for: ";
    std::cin >> myNum;
    index = searchArray(numbers, size_of_Array, myNum);

    if (index != -1)
    {
        std::cout << myNum << " is at index " << index ;
    }
    else
    {
        std::cout << myNum << " is not in the array";
    }



    return 0;
}
*/
// Example -----------------------------------------------2

#include <iostream>

int searchArray(std::string array[], int size_of_Array, std::string element)
{
    for (int i = 0; i < size_of_Array; i++)
    {
        if(array[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    std::string foods[] = {"Hanu", "Thaipong", "Jambura", "Kochu", "Peas", "Beans", "Vegetables", "Sayngkum"};
    int size_of_Array = sizeof(foods) / sizeof(foods[0]) ;
    int index;
    std::string myFood;
    std::cout << "Enter element to search for: ";
    std::getline(std::cin, myFood);
    index = searchArray(foods, size_of_Array, myFood);

    if (index != -1)
    {
        std::cout << myFood << " is at index " << index ;
    }
    else
    {
        std::cout << myFood << " is not in the array";
    }

    return 0;
}
