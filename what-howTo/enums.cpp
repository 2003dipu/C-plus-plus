
/*
#include <iostream>
using namespace std;
enum Suit
{
    Diamonds,
    Hearts,
    Clubs,
    Spades
};
int main()
{
    Suit hand;
    // Assume that some enum value is set for hand
    // In this example, each case is handled separately
    switch (hand)
    {
    case Diamonds:
        cout << "got Diamonds \n";
        break;
    case Hearts:
        cout << "got Hearts \n";
        break;
    case Clubs:
        cout << "got Clubs \n";
        break;
    case Spades:
        cout << "got Spades \n";
        break;
    default:
        cout << "didn't get card \n";
    }
    // In this example, Diamonds and Hearts are handled one way, and
    // Clubs, Spades, and the default value are handled another way
    switch (hand)
    {
    case Diamonds:
    case Hearts:
        cout << "got a red card \n";

    case Clubs:
    case Spades:
    default:
        cout << "didn't get a red card \n";
    }
}
*/
/*
#include <iostream>
using namespace std;

namespace CardGame_Scoped
{
    enum class Suit
    {
        Diamonds,
        Hearts,
        Clubs,
        Spades
    };
    void PlayCard(Suit suit)
    {
        if (suit == Suit::Clubs) // Enumerator must be qualified by enum

        {
            cout << "";
        }
    }
}
namespace CardGame_NonScoped
{
    enum Suit
    {
        Diamonds,
        Hearts,
        Clubs,
        Spades
    };
    void PlayCard(Suit suit)
    {
        if (suit == Clubs) // Enumerator is visible without qualification
        {
            cout << "Good Luck";
        }
    }
}

int main()
{
    cout << "Welcome to Enumeration short for enum";

    return 0;
}
*/

// enums = a user defined data type that consists of paired named-integer constants.
// Great if you a set of potential options
#include <iostream>
using namespace std;

enum Day
{
    saturday = 0,
    sunday = 1,
    monday = 2,
    tuesday = 3,
    wednesday = 4,
    thursday = 5,
    friday = 6,
};

enum Flavor
{
    vanilla, mint, nimpa, nungsihojok, fathikom, mathi, nannum
};

enum Color
{
    red, orange, yellow, green, blue, purple, tanua
};

enum Planet
{
    mercurry = 4880,
    venus = 12104,
    earth = 12756,
    mars = 6794,
    jupiter = 142984,
    saturn = 108728,
    uranus = 51118,
    neptune = 49532,
    pluto = 2320
};

int main()
{
    Day today = tuesday;

    switch (today)
    {
    case saturday:
        cout << "It's Saturday.\n";
        break;
    case sunday:
        cout << "It's Sunday.\n";
        break;
    case monday:
        cout << "It's Monday.\n";
        break;
    case tuesday:
        cout << "It's Tuesday.\n";
        break;
    case wednesday:
        cout << "It's Wednesday.\n";
        break;
    case thursday:
        cout << "It's Thursday.\n";
        break;
    case friday:
        cout << "It's Friday.\n";
        break;
    }

    return 0;
}