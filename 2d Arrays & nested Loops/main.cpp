#include <iostream>

using namespace std;

int main()
{
    cout << "\n\n==============================================================================\n\n";

    int numberGrid[4][3] = { // here 4 = rows, 3 = columns
                                {1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9},
                                {10, 11, 12}

                            };
    string fruits[][5] = {  // here row specification = is optional, column specification = 5 is mandatory
                            {"hanu ", " thaipong ", "jambura ", "koboy ", "jum  "},
                            {"mango ", "jackfruit", "jambura ", "dalim ", "berry"},
                            {"a\t|", "b\t|", "c\t|", "d\t|", "e\t|"},
                            {"1\t|", "2\t|", "3\t|", "4\t|", "5\t|"}

                        };

    for (int i = 0; i < 4; i ++) // here i = corresponds to index of rows
    {
        for (int j = 0; j < 3; j ++) // here j = is responsible for number or index of the columns
        {
            cout << numberGrid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < 4; i ++)
    {
        for (int j = 0; j < 5; j ++)
        {
            cout << fruits[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n\n==============================================================================\n\n";
    return 0;
}