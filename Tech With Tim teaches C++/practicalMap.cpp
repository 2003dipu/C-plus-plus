#include <iostream>
#include <map>

using namespace std;

/*
// you can use this separately in your another project. This is powerful
int main()
{
    cout << "\n\n";
    cout << "\t\t Project Name: iterating through Maps in C++" << endl;

    string test = "Hello World my name is Dipu! hannay a";

    map<char, int> freq;
    for(int i = 0; i < test.length(); ++i)
    {
        char letter = test[i];
        cout << letter << "-";
    }

    cout << "\n\n";
   
}
*/
// practical map example
int main()
{
    cout << "\n\n";
    
    cout << "\t\t Project Name: iterating through Maps in C++" << endl;

    string test = "Hello World my name is Dipu! hannay a";

    map<char, int> freq;
    for(int i = 0; i < test.length(); ++i)
    {
        char letter = test[i];
        if (freq.find(letter) == freq.end())
        {
            freq[letter] = 0;
        }
        freq[letter]++;
    }
    for (auto itr = freq.begin(); itr != freq.end(); ++itr)
    {
        cout << itr->first << ": " << itr->second << endl;
    }
       
    cout << "\n\n";
   
}