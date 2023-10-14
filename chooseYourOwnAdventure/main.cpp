
/*
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    cout << "\n\n==================================================================================================\n\n";

    string name, answer;

    cout << "Type your name: ";
    getline(cin, name);
    cout << "Welcome, " << name << ", to this adventurous journey!\n";
    cout << "\n\n==================================================================================================\n\n";
    // Introduction and Background
    cout << "You find yourself at a crossroad. A path stretches out before you, leading to unknown destinations.\n";

    // First Game: Left or Right Path
    cout << "As you stand there, pondering the two paths ahead, which one will you choose? (left/right/antarctica): ";
    cin >> answer;
    transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

    if (answer == "left")
    {
        cout << "\n\n==================================================================================================\n\n";
        cout << "You decide to take the left path and embark on a new adventure.\n";

        cout << "The path leads you to a dense forest. Do you venture deeper into the forest or turn back? (venture/back): ";
        cin >> answer;
        transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

        if (answer == "venture")
        {
            cout << "\n\n==================================================================================================\n\n";
            cout << "As you venture deeper into the forest, you discover a hidden cave.\n";

            cout << "Inside the cave, you find a glowing crystal. Do you touch it or leave it alone? (touch/leave): ";
            cin >> answer;
            transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

            if (answer == "touch")
            {
                cout << "\n\n==================================================================================================\n\n";
                cout << "As your hand touches the crystal, a surge of energy flows through you.\n";
                cout << "You gain mystical powers and become a legendary hero!\n";
                cout << "Congratulations, " << name << "! You have won the game and unlocked an epic ending!\n";
            }
            else if (answer == "leave")
            {
                cout << "\n\n==================================================================================================\n\n";
                cout << "You decide not to touch the crystal. You leave the cave and continue your journey.\n";
                cout << "The adventure continues...\n";
            }
            else
            {
                cout << "Not a valid option. You lose!\n";
            }
        }
        else if (answer == "back")
        {
            cout << "\n\n==================================================================================================\n\n";
            cout << "You choose to turn back and find yourself back at the crossroad.\n";
            cout << "You decide to take the right path this time.\n";
            // Continue the story...
        }
        else
        {
            cout << "Not a valid option. You lose!\n";
        }
    }
    else if (answer == "right")
    {
        cout << "\n\n==================================================================================================\n\n";
        cout << "You choose the right path and find yourself on a narrow bridge overlooking a chasm.\n";

        cout << "The bridge looks unstable. Do you cross it or head back? (cross/back): ";
        cin >> answer;
        transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

        if (answer == "cross")
        {
            cout << "\n==================================================================================================\n";
            cout << "You cautiously cross the bridge and encounter a mysterious stranger.\n";

            cout << "The stranger offers you a magical amulet. Do you accept it? (yes/no): ";
            cin >> answer;
            transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

            if (answer == "yes")
            {
                cout << "\n\n==================================================================================================\n\n";
                cout << "With the magical amulet in hand, you feel a surge of power.\n";
                cout << "You continue your journey with newfound confidence.\n";
                // Continue the story...
            }
            else if (answer == "no")
            {
                cout << "\n\n==================================================================================================\n\n";
                cout << "You politely decline the offer and continue on your way.\n";
                // Continue the story...
            }
            else
            {
                cout << "\n\n==================================================================================================\n\n";
                cout << "Not a valid option. You lose!\n";
            }
        }
        else if (answer == "back")
        {
            cout << "\n\n==================================================================================================\n\n";
            cout << "You decide not to risk crossing the unstable bridge and turn back.\n";
            cout << "You return to the crossroad and choose the left path this time.\n";
            // Continue the story...
        }
        else
        {
            cout << "Not a valid option. You lose!\n";
        }
    }
    else if (answer == "antarctica")
    {
        cout << "\n\n================================== < Wow. You are courageous! > ==========================================================\n\n";
        cout << "You've chosen to embark on a journey to Antarctica, known for its icy landscapes and hidden treasures.\n";

        cout << "Would you like to travel there by aeroplane or ship? (aeroplane/ship): ";
        cin >> answer;

        if (answer == "aeroplane")
        {
            cout << "\n\n==================================================================================================\n\n";
            cout << "It will take you 10 days to fly from India to Antarctica and will cost you $50,000.\n";
            cout << "Are you ready for it? (yes/no): ";
            cin >> answer;

            if (answer == "yes")
            {
                cout << "\n\n==================================================================================================\n\n";
                cout << "Finally, you landed successfully and safely on Antarctica!\n";
                cout << "You have dug a lot and unearthed $10 billion worth of diamonds. What would you like to do with your wealth now? (I don't know/I know): ";
                cin >> answer;

                if (answer == "I don't know")
                {
                    cout << name << ", you are the richest person on the planet now. Enjoy your life as you please!\n";
                }
                else if (answer == "I know")
                {
                    cout << "\n\n==================================================================================================\n\n";
                    cout << "What is it? Would you like to share it with us? (yes/no): ";
                    cin >> answer;

                    if (answer == "yes")
                    {
                        cout << "\n\n==================================================================================================\n\n";
                        cout << "Thanks for sharing your next adventure with us, " << name << ". We will write your biography using generative AI tools within a week. Enjoy your life!\n";
                    }
                    else
                    {
                        cout << "\n\n==================================================================================================\n\n";
                        cout << name << ", you declined to share your next adventure. You have chosen to live an ordinary life.\n";
                    }
                }
                else
                {
                    cout << "Not a valid option. You lose!\n";
                }
            }
            else
            {
                cout << name << ", you declined to be ready for your adventure to Antarctica. Save up money and let us know when you are ready.\n";
            }
        }
        else if (answer == "ship")
        {
            cout << "\n\n==================================================================================================\n\n";
            cout << "It will take you 2 months to get there and cost you $30,000.\n";
            cout << "Are you ready for it? (yes/no): ";
            cin >> answer;

            if (answer == "yes")
            {
                cout << "\n\n==================================================================================================\n\n";
                cout << "After a long journey, you arrived at Antarctica!\n";
                // Continue the story...
            }
            else
            {
                cout << "\n\n==================================================================================================\n\n";
                cout << name << ", you declined to be ready for your adventure to Antarctica. Save up money and let us know when you are ready.\n";
            }
        }
        else
        {

            cout << "Not a valid option. You lose!\n";
        }
    }
    else
    {
        cout << "Not a valid option. You lose!\n";
    }
    cout << "\n\n==================================================================================================\n\n";
    cout << "Thank you for playing! Remember, every choice shapes your destiny.\n";
    cout << "Thank you for taking life as a game. Always remember: If you set your dreams ridiculously high, even if you fail, you will fall above everyone else's success!\n";

    cout << "\n\n==================================================================================================\n\n";
    return 0;
}
*/
// alternative using class

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class AdventureGame
{
public:
    void start()
    {
        cout << "Type your name: ";
        getline(cin, name);
        cout << "Welcome, " << name << ", to this adventurous journey!\n";

        // Introduction and Background
        cout << "You find yourself at a crossroad. A path stretches out before you, leading to unknown destinations.\n";

        // First Game: Left or Right Path
        getInput("As you stand there, pondering the two paths ahead, which one will you choose? (left/right/antarctica): ", answer);

        if (answer == "left")
        {
            print("You decide to take the left path and embark on a new adventure.");
            leftPath();
        }
        else if (answer == "right")
        {
            print("You choose the right path and find yourself on a narrow bridge overlooking a chasm.");
            rightPath();
        }
        else if (answer == "antarctica")
        {
            print("You've chosen to embark on a journey to Antarctica, known for its icy landscapes and hidden treasures.");
            antarcticaPath();
        }
        else
        {
            print("Not a valid option. You lose!");
        }

        print("Thank you for playing! Remember, every choice shapes your destiny.");
        print("Thank you for taking life as a game. Always remember: If you set your dreams ridiculously high, even if you fail, you will fall above everyone else's success!");
    }

private:
    string name;
    string answer;

    void getInput(const string &prompt, string &input)
    {
        cout << prompt;
        cin >> input;
        transform(input.begin(), input.end(), input.begin(), ::tolower);
    }

    void print(const string &message)
    {
        cout << message << "\n";
    }

    void leftPath()
    {
        print("The path leads you to a dense forest. Do you venture deeper into the forest or turn back? (venture/back): ");
        getInput("", answer);

        if (answer == "venture")
        {
            print("As you venture deeper into the forest, you discover a hidden cave.");
            print("Inside the cave, you find a glowing crystal. Do you touch it or leave it alone? (touch/leave): ");
            getInput("", answer);

            if (answer == "touch")
            {
                print("As your hand touches the crystal, a surge of energy flows through you.");
                print("You gain mystical powers and become a legendary hero!");
                print("Congratulations, " + name + "! You have won the game and unlocked an epic ending!");
            }
            else if (answer == "leave")
            {
                print("You decide not to touch the crystal. You leave the cave and continue your journey.");
                print("The adventure continues...");
            }
            else
            {
                print("Not a valid option. You lose!");
            }
        }
        else if (answer == "back")
        {
            print("You choose to turn back and find yourself back at the crossroad.");
            print("You decide to take the right path this time.");
            // Continue the story...
        }
        else
        {
            print("Not a valid option. You lose!");
        }
    }

    void rightPath()
    {
        print("The bridge looks unstable. Do you cross it or head back? (cross/back): ");
        getInput("", answer);

        if (answer == "cross")
        {
            print("You cautiously cross the bridge and encounter a mysterious stranger.");
            // Continue the story...
        }
        else if (answer == "back")
        {
            print("You decide not to risk crossing the unstable bridge and turn back.");
            print("You return to the crossroad and choose the left path this time.");
            // Continue the story...
        }
        else
        {
            print("Not a valid option. You lose!");
        }
    }

    void antarcticaPath()
    {
        print("Would you like to travel there by aeroplane or ship? (aeroplane/ship): ");
        getInput("", answer);

        if (answer == "aeroplane")
        {
            print("It will take you 10 days to fly from India to Antarctica and will cost you $50,000.");
            // Continue the story...
        }
        else if (answer == "ship")
        {
            print("It will take you 2 months to get there and cost you $30,000.");
            // Continue the story...
        }
        else
        {
            print("Not a valid option. You lose!");
        }
    }
};

int main()
{
    AdventureGame game;
    game.start();
    return 0;
}
