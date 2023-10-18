#include <iostream>
#include <tuple>
using namespace std;

/*
int main()
{
    tuple <int, string, bool> person(20, "Rosmi", true) ;
    //cout << get<1>(person) << endl;
    get<1>(person) = "Anushka";
    //cout << get<1>(person);

    tuple <int, char, bool, float> thing;
    thing = make_tuple(23, 'H', true, 23.5);
    cout << get<0>(thing) << "\t";
    cout << get<1>(thing) << "\t";
    cout << get<2>(thing) << "\t";
    cout << get<3>(thing) << "\t";
   
    return 0;
}


// swapping tuples
int main()
{
    tuple <int, int> t1 = make_tuple(1, 2);
    tuple <int, int> t2 = make_tuple(3, 4);
    t2.swap(t1); // swap for the first time
    t2.swap(t1); // reswap or swap second time

    cout << get<0>(t1) << endl;
    cout << get<1>(t1) << endl;
    cout << get<0>(t2) << endl;
    cout << get<1>(t2) << endl;

    return 0;
}

// decomposing tuples
int main()
{
    tuple < int, int > t1 = make_tuple (1, 2);
    int x, y;

    tie (x, y) = t1;
    cout << x << " ";
    cout << y << endl;

    return 0;
}
*/

// concatenating tuples
int main()
{
    cout << "\n\n";
    
    tuple < int, char > t1(20, 'T');
    tuple < char, string > t2 ('R', "Hello World!");
    auto t3 = tuple_cat(t1, t2);
    cout << get<0>(t3) << "\t";
    cout << get<1>(t3) << "\t";
    cout << get<2>(t3) << "\t";
    cout << get<3>(t3) << "\t";

    cout << "\n\n";
    return 0;
}