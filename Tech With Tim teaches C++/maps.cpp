#include <iostream>
#include <map>

using namespace std;

/*
int main()
{
    cout << "\n\n";
    cout << "\t\t Project Name: Maps in C++" << endl;

    map<char, int> mp = {
        {'T', 7},
        {'S', 8},
        {'a', 4}};
        mp['u'] = 9;
        pair<char, int> p1('j', 5);
        mp.insert(p1);
        mp.erase(p1.first);
        mp.clear();

    cout << mp.empty() << endl;

    cout << "\n\n";
   
}
*/
// iterating through maps
/*
int main()
{
    cout << "\n\n";
    cout << "\t\t Project Name: iterating through Maps in C++" << endl;

    map<char, int> mp = {
        {'T', 7},
        {'S', 8},
        {'a', 4}};
        mp['u'] = 9;
        pair<char, int> p1('j', 5);
        mp.insert(p1);

    for (map<char, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr)
    {
        cout << (*itr).first << "\t"; // dereference operator
        cout << (*itr).second << endl;
    }

    cout << "\n\n";
   
}
*/
//alternative way with pointers ->
int main()
{
    cout << "\n\n";
    cout << "\t\t Project Name: iterating through Maps in C++" << endl;

    map<char, int> mp = {
        {'T', 7},
        {'S', 8},
        {'a', 4}};
        mp['u'] = 9;
        pair<char, int> p1('j', 5);
        mp.insert(p1);

    for (map<char, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr)
    {
        cout << itr->first << "\t";
        cout << itr->second << endl;
    }

    cout << "\n\n";
   
}
