
// How to sort an array in C++
// example ---------------------------1: simple bubble sort algorithm
/*
#include <iostream>

void sort(int numbers[], int sizeA)
{
    int temp;
    for(int i = 0; i < sizeA - 1; i++)
    {
        for(int j = 0; j < sizeA - i - 1; j ++)
        {
            if(numbers[j] > numbers[j + 1]) // ascending order sorting. To sort descending order use '<' instead of '>'
            {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int numbers[] = {2,54,3,22,4,64,2,6,74};
    int sizeA = sizeof(numbers) / sizeof(numbers[0]);
    sort(numbers, sizeA);// numbers[] array is now sorted here.
    for(int number : numbers)
    {
        std::cout << number << " ";
    }
    return 0;
}
*/

// example ---------------------------2: divide-and-conquer algorithm
/*
#include <iostream>

int partition(int numbers[], int low, int high) {
  int pivot = numbers[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (numbers[j] <= pivot) {
      i++;
      std::swap(numbers[i], numbers[j]);
    }
  }
  std::swap(numbers[i + 1], numbers[high]);
  return i + 1;
}

void quicksort(int numbers[], int low, int high) {
  if (low < high) {
    int pivot = partition(numbers, low, high);
    quicksort(numbers, low, pivot - 1);
    quicksort(numbers, pivot + 1, high);
  }
}

int main() {
  int numbers[] = {2, 54, 3, 22, 4, 64, 2, 6, 74};
  int sizeA = sizeof(numbers) / sizeof(numbers[0]);

  quicksort(numbers, 0, sizeA - 1);

  for (int number : numbers) {
    std::cout << number << " ";
  }

  std::cout << std::endl;

  return 0;
}
*/
/*
// example ---------------------------3: built-in sort function >  sort between the range (first, last)
#include <iostream>
#include <algorithm> // include the algorithm library

int main()
{
    int numbers[] = {2, 54, 3, 22, 4, 64, 2, 6, 74};
    // Calculate the size of the array using the sizeof operator
    int sizeA = sizeof(numbers) / sizeof(numbers[0]);
    // Sort the array using std::sort in ascending order.
    std::sort(numbers, numbers + sizeA); 
    // Print the sorted array.
    for (int number : numbers)
    {
        std::cout << number << " ";
    }
    std::cout << std::endl;
    return 0;
}
*/

// example ---------------------------4: built-in sort function >  sort between a specified range (m, n)
#include <iostream>
#include <algorithm>

int main() {
    int numbers[] = {2, 54, 3, 1, 2, -5, 4, 6, 74, 12};
    int sizeA = sizeof(numbers) / sizeof(numbers[0]);

    // Sort only a subrange (e.g., from index 2 to 6)
    std::sort(numbers + 2, numbers + 8);

    for (int number : numbers) {
        std::cout << number << " ";
    }

    return 0;
}
