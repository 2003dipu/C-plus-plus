// Tim Russica Explains the code
#include <iostream>
#include <set>


using namespace std;

int main()
{
    cout << "\n\n\n";
    string sentence_a = "This is an example of speech synthesis in English. You can succeed at anything if you are determined to do so.";
    string sentence_b = "xyz abc def ghi jkl mno pqr stu vwx yz.";
    
    set<char> ofa;
    //set<char> ofb;
    for (int i = 0; i < sentence_a.length(); ++i)
    {
        char letter = sentence_b[i];
        ofa.insert(letter);
    }

    for (int i = 0; i < sentence_a.length(); ++i)
    {
        char letter = sentence_a[i];
        ofa.erase(letter);
        
    }

    if (ofa.size() > 0)
    {
        cout << "No! sentence_a does not have all the letters in sentence_b!";
    } else{
        cout << "Yes! sentence_a have all the letters found in sentence_b";
    }

    cout << "\n\n\n";
    return 0;
}