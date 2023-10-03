
/*
In C++, a multidimensional array is an array that has more than one dimension. While C++ supports one-dimensional
arrays, you can create arrays with two or more dimensions to represent data in a grid-like or tabular format.
Multidimensional arrays are often used to store data in matrices, tables, or grids.

Here's a brief overview of how to declare and use multidimensional arrays in C++:

1. Declaration:
   To declare a multidimensional array, you specify the number of dimensions in square brackets. For example,
   to declare a 2D array, you use two sets of square brackets:

   int myArray[3][4]; // A 2D array with 3 rows and 4 columns

   You can also have arrays with more dimensions, such as 3D arrays or even higher-dimensional arrays.

2. Initialization:
   You can initialize multidimensional arrays at the time of declaration:


   int myArray[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

   This initializes a 2D array with specific values for each element.

3. Accessing Elements:
   To access elements in a multidimensional array, you use multiple indices. For example:

   int value = myArray[1][2]; // Accesses the element in the second row and third column (7)

4. Iterating through Multidimensional Arrays:
   You can use nested loops to iterate through the elements of a multidimensional array. For a 2D array,
    you would typically use two nested loops:

   for (int i = 0; i < 3; ++i) {
       for (int j = 0; j < 4; ++j) {
           cout << myArray[i][j] << " ";
       }
       cout << endl;
   }

5. Dynamic Allocation:
   You can also create multidimensional arrays dynamically using pointers and the `new` operator for heap
   allocation. For example, a dynamically allocated 2D array might look like this:

   int** myArray = new int*[3];
   for (int i = 0; i < 3; ++i) {
       myArray[i] = new int[4];
   }

Don't forget to deallocate the memory when you're done using `delete[]` for each sub-array and `delete[]`
for the array of pointers.
Multidimensional arrays are a powerful way to store and manipulate structured data in C++, especially when
 dealing with matrices, tables, or grids. However, it's essential to be mindful of array bounds and memory
 management when working with them. Additionally, C++ offers alternatives like using `std::vector` or
 multidimensional arrays provided by libraries like the Eigen library for more advanced matrix and linear
 algebra operations.

*/
/*
// Example ------------1
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Define the size of the 2D array
    const int numStudents = 3;
    const int numFields = 2;  // Two fields: Name and Registration Number

    // Declare and initialize the 2D array with student names and registration numbers
    string studentInfo[numStudents][numFields] = {
        {"Cabin", "2001"},
        {"Jack", "2002"},
        {"Steve", "2003"}
    };

    // Iterate through the 2D array and print the student names and registration numbers
    for (int i = 0; i < numStudents; ++i) {
        cout << studentInfo[i][0] << " : " << studentInfo[i][1] << endl;
    }

    return 0;
}
// Example ------------2
*/
// Example ------------2(fill 2D array with user input)
// Enable the user to input their full name and registration num: (updated code to the above code)
/*
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Define the size of the 2D array
    const int numStudents = 3;
    const int numFields = 2;  // Two fields: Name and Registration Number

    // Declare the 2D array to store student names and registration numbers
    string studentInfo[numStudents][numFields];

    // Prompt the user to enter student information
    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter full name for student " << (i + 1) << ": ";
        getline(cin, studentInfo[i][0]);  // Read the full name
        cout << "Enter registration number for student " << (i + 1) << ": ";
        cin >> studentInfo[i][1];  // Read the registration number
        cin.ignore();  // Clear the newline character from the input buffer
    }

    // Print the student names and registration numbers
    cout << "\nStudent Information:\n Student Name   | Registration Number" << endl;
    for (int i = 0; i < numStudents; ++i) {
        cout << studentInfo[i][0] << " :      " << studentInfo[i][1] << endl;
    }
    cout << "\n";

    return 0;
}
*/
// Example ------------3
/*
#include <iostream>

int main()
{
    std::cout << "\n------------------------------------------------------------------                         \n";
    // std::string array_name[rows][columns] (for declaration)
    // 2D array = {array1, array2, array3};
    std::string cars[][3] = {
                                {"Mustang" , "Escape"    , "F-150"     },
                                {"Corvette", "Equinox"   , "Silverado" },
                                {"Durango" , "Challenger", "Ram 1500"  },
                                {"Honda"   , "Tesla"     , "Diang"     }
                            };
    std::cout << "Manual typing and printing within 12 lines----> \n\n";

    std::cout << cars[0][0] << "    ";
    std::cout << cars[0][1] << "      ";
    std::cout << cars[0][2] << "\n";
    std::cout << cars[1][0] << "   ";
    std::cout << cars[1][1] << "     ";
    std::cout << cars[1][2] << " \n";
    std::cout << cars[2][0] << "    ";
    std::cout << cars[2][1] << "  ";
    std::cout << cars[2][2] << "\n";
    std::cout << cars[3][0] << "        ";
    std::cout << cars[3][1] << "        ";
    std::cout << cars[3][2] << "     \n";

    std::cout << "\nAutomating the above code with multiple for loops within 19 lines lines----> \n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << cars[0][i] << "        ";
    }
    std::cout << " \n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << cars[1][i] << "       ";
    }
    std::cout << " \n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << cars[2][i] << "       ";
    }
    std::cout << " \n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << cars[3][i] << "             ";
    }

    std::cout << "\n------------------------------------------------------------------                         \n";
    return 0;
}
*/
/*
// Example ------------4
#include <iostream>
int main() {

	std::string cars[][3] = {{"Mustang", "Escape", "F-150"},
					      {"Corvette", "Equinox", "Silverado"},
					      {"Challenger", "Durango", "Ram 1500"}};

	int rows = sizeof(cars)/sizeof(cars[0]);
	int columns = sizeof(cars[0])/sizeof(cars[0][0]);

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			std::cout << cars[i][j] << " ";
		}
		std::cout << '\n';
	}

    return 0;
}
*/
// Example ------------5 (Challenge project I made up or imagined and  I solved alone) on 3 October 2023 evening within 2 hours
//Automating the above code with 1 nested for loop within 8 lines
#include <iostream>

int main()
{
    std::cout << "\n------------------------------------------------------------------                         \n";
    std::string cars[][3] = {   // coumn #0   coumn #1        coumn #2
                                {"Mustang" , "Escape"    , "F-150"    },   // row =   #0 ---> cars[row,column]
                                {"Corvette", "Equinox"   , "Silverado"},  // row =    #1
                                {"Durango" , "Challenger", "Ram 1500" }, // row =     #2
                                {"Honda"   , "Tesla"     , "Diang"    } // row =      #3
                            };
    for (int i = 0; i < 4; i++)
    {                               // outer loop prints the rows through i (4 rows here 0,1,2,3)
        for (int j = 0; j < 3; j++)
        {                           // inner loop prints the columns through j( 3 columns here 0,1,2)
            if (i == 0)
            {
                std::cout << "Ford Company: |" << cars[i][j] << "|             ";
            }
            else if (i == 1)
            {
                std::cout << "Chaperlay Company: |" << cars[i][j] << "|             ";
            }
            else if (i == 2)
            {
                std::cout << "Dodge Company: |" << cars[i][j] << "|             ";
            }
            else if (i == 3)
            {
                std::cout << "Tesla Company: |" << cars[i][j] << "|             ";
            }
        }
        std::cout << " \n";
    }
    std::cout << "\n------------------------------------------------------------------                         \n";
    return 0;
}