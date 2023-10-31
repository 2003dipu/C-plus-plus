#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a structure to represent game locations
struct Location
{
    string name;
    string description;
    vector<string> connectedLocations;
};

class AdventureGame
{
private:
    vector<Location> worldMap;
    int currentLocation;

public:
    AdventureGame();
    ~AdventureGame();

    void runGame();
};

AdventureGame::AdventureGame()
{
    // Initialize the game's world map with locations
    worldMap = {
        {"Forest", "You are in a dark forest. It's full of tall trees.", {"Cave"}},
        {"Cave", "You find yourself in a cold, damp cave.", {"Forest", "Treasure Room"}},
        {"Treasure Room", "You've discovered a room full of treasures!", {"Cave"}}};

    // Set the initial location
    currentLocation = 0; // Start in the Forest
}

AdventureGame::~AdventureGame() {}

void AdventureGame::runGame()
{
    cout << "Welcome to the Text-Based Adventure Game!\n";

    // Main game loop
    while (true)
    {
        Location current = worldMap[currentLocation];
        cout << "\n"
             << current.name << "\n";
        cout << current.description << "\n";

        // Print available options to the player
        cout << "You can go to: ";
        for (size_t i = 0; i < current.connectedLocations.size(); ++i)
        {
            cout << current.connectedLocations[i];
            if (i < current.connectedLocations.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "\n";

        // Get player input
        string input;
        cout << "Enter a command (e.g., 'go Cave' or 'quit'): ";
        cin >> input;

        // Handle player commands
        if (input == "quit")
        {
            cout << "Thanks for playing!\n";
            break;
        }
        else if (input.find("go ") == 0)
        {
            // Extract the location name from the input
            string destination = input.substr(3);

            // Check if the destination is valid from the current location
            bool validMove = false;
            for (const string &location : current.connectedLocations)
            {
                if (location == destination)
                {
                    validMove = true;
                    break;
                }
            }

            if (validMove)
            {
                // Find the index of the destination location
                for (size_t i = 0; i < worldMap.size(); ++i)
                {
                    if (worldMap[i].name == destination)
                    {
                        currentLocation = static_cast<int>(i);
                        break;
                    }
                }
            }
            else
            {
                cout << "You can't go there from here!\n";
            }
        }
        else
        {
            cout << "Invalid command. Try 'go [Location]' or 'quit'.\n";
        }
    }
}

int main()
{
    AdventureGame game;
    game.runGame();

    return 0;
}
