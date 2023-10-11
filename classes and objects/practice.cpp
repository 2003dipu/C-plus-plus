
/*
#include <iostream>
#include <vector>
using namespace std;

class Successful
{
private:
    string deed = "Hard work on a project";
    vector<string> HumanLanguages = {"Bishnuprya Monipuri", "Bangla", "Hindi", "English"};
    int nHumanLanguages = HumanLanguages.size();
    void printHumanLanguages()
    {
        cout << "\tI am proficient in the following " << nHumanLanguages << " human languages: " << endl;
        for (int i = 0; i < nHumanLanguages; i ++)
        {
            cout << "\t" << i + 1 << ". " << HumanLanguages[i] << endl;
            
        }
    }

public:
    vector <string> ProgrammingLanguages = {"Python", "C#", "C++", "JavaScript", "Dart"};
    vector <string> :: size_type nProgrammingLanguages = ProgrammingLanguages.size();

    void printProgrammingLanguages()
    {
        cout << "\tI am proficient in the following " << nProgrammingLanguages << " programming languages: " << endl;
        for (int i = 0; i < nProgrammingLanguages; i ++)
        {
            cout << "\t" << i + 1 << ". " << ProgrammingLanguages[i] << endl;
            
        }
        cout << "----------------------------------------------------------------------------------\n";
        printHumanLanguages();
    }
};

int main()
{
    cout << "\n\n================================================================================\n\n";
    Successful success1;

    success1.printProgrammingLanguages();

    cout << "\n\n================================================================================\n\n";
    return 0;
}
*/
// Example=============== 2

#include <iostream>
#include <vector>
using namespace std;

class Successful
{
private:
    vector<string> HumanLanguages = {"Bishnuprya Monipuri", "Bangla", "Hindi", "English"};
    vector<string> ProgrammingLanguages = {"Python", "C# on .NET", "C++", "JavaScript", "Dart on Flutter", "HTML with CSS"};

public:
    

    void printLanguages(const vector<string> &languages, const string &type)
    {
        cout << "I am proficient in the following " << type << " languages:" << endl;
        for (int i = 0; i < languages.size(); i++)
        {
            cout << i + 1 << ". " << languages[i] << endl;
        }
    }

    // Public method to access HumanLanguages
    void printHumanLanguages()
    {
        printLanguages(HumanLanguages, "human");
    }
    void printProgrammingLanguages()
    {
        printLanguages(ProgrammingLanguages, "programming");
    }
};

int main()
{
    cout << "\n\n==============================================================================\n\n";
    cout << "What's your name?:\t";
    string name;
    getline(cin, name);
    cout << "------------------------------------------------------------------------------\n";
    cout << "My name is " << name << endl;

    Successful success1;

    cout << "===============================================================================" << endl;
    cout << "\t\t< Project Name: Show off my Skills > \n" << endl;
    success1.printHumanLanguages();
    cout << "------------------------------------------------------------------------------" << endl;
    success1.printProgrammingLanguages();

    cout << "\n\n===============================================================================\n\n";

    return 0;
}
