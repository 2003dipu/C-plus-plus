#include <iostream>
#include <vector>

using namespace std;
// vector = in C++ vectors are sequence containers representing arrays that can change in size.

/*
int main()
{
    cout << "\n\n==============================================================================\n\n";

    cout << "\t\tProject Name: Vectors(dynamic arrays) in C++\n\n";
    vector < int > v1 = {1, 2, 3, 4, 5, -23, 0, 54};
    cout << v1[2] << endl;
    cout << v1.front() << endl; // access the  starting or first element of the vector
    cout << v1.back() << endl;// vice versa
    cout << "Number of elements or size of the vector 1D array is: " << v1.size() << endl;
    v1.push_back(4); // appending an element at the end of the vector
    v1.push_back(4);
    v1.push_back(4);
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    v1.shrink_to_fit();
    v1.shrink_to_fit();
    cout << "The capacity of the 1D array vector v1 is: " << v1.capacity() << endl;// capacity of the vector

    cout << "\n\n==============================================================================\n\n";
    return 0;
}
*/
/*
// basic vector functions or methods or techniques or systems
int main()
{
    
    vector <int > v1 = {1, 2, 3, 4, 6, 7, 8, 9, 10};
    int n = v1.size(); // counts the size of the array or the number of elements in the array.
    cout << "Size of the vector or the length of the vector is: " << n << endl;
    
    v1.insert(v1.begin(), 0);      // adding elements to the beginning of the array
    v1.insert(v1.begin() + n/2, 5); // adding elements at the middle of the array
    v1.insert(v1.end(), 11); // adding(appending or concatenating) elements at the end of the array
    v1.erase(v1.begin());

    for (int i = 0; i < v1.size(); i ++)
    {
        cout << v1[i] << " ";
    }
    
    
    return 0;
}
*/
// iterating through 1D array vectors

int main()
{
    vector <int> v1 = {1, 2, 3, 4, 5, 6};

    for (int i = 0; i < v1.size(); i ++)
    {
        cout << v1[i] << endl;
    }
    // or alternative code

    v1.insert(v1.begin(), 0); // insert a new element in the array at the index of 0, doesn't replace anything, add elements
    
    for (auto itr = v1.begin(); itr != v1.end(); ++itr)
    {
        cout << *itr << endl;
    }

    int array1[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9}; // using arrar1.size() is not made accessible in C++
    array1[0] = 0; // replaces the elements of the array at the index of 0
    cout << "\nUsing arrays without vectos\n";
    for (int i = 0; i < sizeof(array1)/sizeof(array1[0]); i ++)
    {
        cout << array1[i] << endl;
    }

    return 0;
}
// run this code to do your own research, you will understand what I meant to say by the comments and the example codes
