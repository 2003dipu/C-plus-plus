/* what are sets in C++? = sets are a type of associative containers in which each element has to be unique,
the value of the element identifies it. or A set is an unordered collection of unique elements.
it prints value in alphabetical order.number comes first >
Capital letter or upper case letter comes before > lower case letters
*/

#include <iostream>
#include <set>
using namespace std;

/*
int main()
{
    cout << "\n\n\t\tProject Name: Sets in C++\n\n";
    set <char> s1 = {'C', 'D', 'F', 'C', 'b', 'a','A', '5', '1', '3', '2'};
    //s1.insert('B');
    s1.insert('E');
    //s1.erase('A');
    //s1.clear();
    if (s1.find('B') == s1.end())
    {
        cout << "Could not find B" << endl;
    }
    else{
        cout << "Found C inside the set " << endl;
    }

    for (auto itr = s1.begin(); itr != s1.end(); ++itr)
    {
        cout << *itr << endl;
    }

    return 0;
}
*/
// practical set example .................................> practical > important for laying the foundation
// set never print a letter or a character more than once
/*
int main()
{
    int counter = 0;

    string test = "!This is an example of speech synthesis in English! This This should be printed twice but the set won't listen";
    set <char> set_1;

    for (int i = 0; i < test.length(); ++i)
    {
        char letter = test[i];
        set_1.insert(letter);
    }

    for (auto itr = set_1.begin(); itr != set_1.end(); ++itr)
    {
        cout << *itr << " ";
        counter ++;
    }
    cout << "\nThe length of the string is: " << test.length() <<"\nThere are " << counter << " different letters! \n";
}
*/

// another example: <<< a problem >>> to determine Yes, you can determine if all the letters in the string
// find are present in the string test elegantly using sets.

#include <iostream>
#include <set>
using namespace std;

int main()
{
    string test = "\nThis is an example of speech synthesis in English.\n";
    string find = "hello";

    // Create sets to store unique characters in both strings
    set<char> testSet(test.begin(), test.end());
    set<char> findSet(find.begin(), find.end());
    

    bool allCharactersFound = true;

    // Check if all characters in 'find' are present in 'test'
    for (char c : findSet)
    {
        if (c != ' ' && testSet.find(c) == testSet.end())
        {
            allCharactersFound = false;
            break;
        }
    }

    if (allCharactersFound)
    {
        cout << "All characters in 'find' are present in 'test.'" << endl;
    }
    else
    {
        cout << "Not all characters in 'find' are present in 'test.'" << endl;
    }

    return 0;
}
// Python code to understand C++ code
/*
I know this C++ code is difficult to comprehend. It will be easy to understand in Python: Let's do that--------------=

test = "\nThis is an example of speech synthesis in English.\n"
find = "hello dear"

# Create sets to store unique characters in both strings
test_set = set(test)
find_set = set(find)

all_characters_found = True

# Check if all characters in 'find' are present in 'test'
for c in find_set:
    if c != ' ' and c not in test_set:
        all_characters_found = False
        break

if all_characters_found:
    print("All characters in 'find' are present in 'test.")
else:
    print("Not all characters in 'find' are present in 'test.")

*/


/*                                  <<------------Explanation---------------------->>
We start by including the necessary libraries and defining the test and find strings that you provided.

Next, we create two sets, testSet and findSet, to store the unique characters in the test and find strings.
We do this by iterating through each character in the strings and adding them to the sets. Sets automatically
store unique elements, so duplicate characters are ignored.

We also initialize a boolean variable allCharactersFound to true. This variable will be used to keep track
of whether all characters in the find string are present in the test string.

We use a for loop to iterate through each character c in the findSet, which contains the unique characters in 
the find string. Inside the loop, we check if the character c is not a space (we skip spaces as they don't need
to be checked). We do this using the condition c != ' '.

We then check if the character c exists in the testSet by using testSet.find(c). The find function is a method 
provided by the set, and it searches for an element in the set. If the element is not found, find returns an 
iterator pointing to the end of the set, which is checked with testSet.end().

If the character c is not found in the testSet, we set allCharactersFound to false to indicate that not all 
characters in the find string are present in the test string.

We also use the break statement to exit the loop early since we've determined that not all characters are present, 
and there's no need to continue checking.

Finally, after the loop, we check the value of allCharactersFound. If it's still true, it means that all characters 
in the find string are present in the test string, and we print a message indicating that. If it's false, we print 
a message indicating that not all characters in find are present in test.
In summary, this code creates sets to store unique characters from both strings, iterates through the characters in
the find string, and checks if they are all present in the test string while skipping spaces. The result is then 
printed to the console.

*/