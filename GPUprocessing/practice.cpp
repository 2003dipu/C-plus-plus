#include<iostream>
#include<vector>

using namespace std;

class testPractice
{
    public:
    vector<int> numArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    public:

    void printToConsole()
    {
        cout << "I print whatever you instruct me to\nThe array is:\n";
        for(int num : numArray)
        {
            cout << num << " ";
        }
        cout << "\n\n--------------------------------------------------------------------------\n";
        
        for (int i = 0; i < numArray.size(); i++)
        {
            numArray[i] *=numArray[i];
        }
        cout << "Array squared\n";
        for(int num : numArray)
        {
            cout << num << " ";
        }
        
    }

};

int main()
{
    cout << "\n\n-------------------------------------------------------------------\n";
    testPractice tP;

    tP.printToConsole();


    cout << "\n\n-----------------------------------------------------------------\n";
    return 0;
}