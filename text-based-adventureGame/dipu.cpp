#include <iostream>
#include <vector>
using namespace std;

class Questionnaire
{
private:
    vector<string> uChoice = {"move on", "go back", "yes", "no"};

public:
    void run()
    {
        string input;
        cout << "\n-----------------------------------------------------------------------------------------------------\n";
        cout << "You are in a dark forest. It's full of tall trees.\nDo you want to traverse it?\n";
        cout << "Enter your choice: \n-> "
             << uChoice[2] << "\n"
             << uChoice[3] << "\n";
        getline(cin, input);

        if (input == uChoice[2])
        {
            cout << "-------------------------------------------------------------------------------------------------------\n";
            cout << "You find yourself in a cold, damp cave.\nWhat would you do?\n";
            cout << "Enter your choice: \n-> "
                 << uChoice[0] << "\n"
                 << uChoice[1] << "\n";
            getline(cin, input);

            if (input == uChoice[0])
            {
                cout << "-------------------------------------------------------------------------------------------------------\n";
                cout << "You see some debris of gold and diamonds inside the cave.\nWhat would you do?\n";
                cout << "Do you spend time picking up the diamonds and golds?\n";
                cout << "Enter 'yes' to collect them or 'go back' \n-> "
                     << uChoice[2] << "\n"
                     << uChoice[1] << "\n";
                getline(cin, input);

                if (input == uChoice[2])
                {
                    cout << "--------------------------------------------------------------------------------------------------------------------------\n";
                    cout << "You start collecting the gold and diamonds, but suddenly, you hear a strange noise behind you.\n";
                    cout << "Do you investigate the noise, or do you continue collecting? Enter 'yes' to investigate or 'no' to continue collecting: \n->";
                    getline(cin, input);

                    if (input == uChoice[2])
                    {
                        cout << "-----------------------------------------------------------------------------------------------------\n";
                        cout << "You cautiously move towards the source of the noise and discover a hidden passage deeper into the cave.\n";
                        cout << "Enter 'move on' to explore the passage or 'go back' to return to collecting: \n->";
                        getline(cin, input);
                    }
                    else if (input == uChoice[3])
                    {
                        cout << "\n---------------------------------------------------------------------------------------------------\n";
                        cout << "!!!\tTo your surprise, unknown surrounds you and you fall asleep forever.\t!!!\n";
                        cout << "\n\n|||||||| Life over -> Game Over |||||||||||\n\n";
                        cout << "-----------------------------------------------------------------------------------------------------\n";
                    }
                }

                if (input == uChoice[0])
                {
                    cout << "---------------------------------------------------------------------------------------------------------\n";
                    cout << "You decide to explore the passage and find yourself in a vast underground chamber.\n";
                    cout << "In the chamber, there is an ancient chest. What will you do?\n";
                    cout << "Enter 'open' to open the chest or 'go back' to leave it: \n";
                    getline(cin, input);

                    if (input == "open")
                    {
                        cout << "You open the chest and discover a magical amulet that grants you special powers.\n";
                        cout << "You continue your adventure with newfound abilities!\n";
                    }
                }
            }
        }
        else if (input == uChoice[3])
        {
            cout << "You decide not to traverse the forest and find another path to continue your adventure.\n";
        }
    }
};

int main()
{
    Questionnaire game;

    game.run();

    return 0;
}
// You can add more real life situations to make this game more engaging. I leave it up to you!