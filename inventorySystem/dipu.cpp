#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a structure to represent an inventory item
struct InventoryItem
{
    string name;
    string id;
    int quantity;
    double price;
};

// Function to display a menu and get user's choice
int displayMenu()
{
    int choice;
    cout << "Inventory System Menu:" << endl;
    cout << "1. Add Item" << endl;
    cout << "2. Remove Item" << endl;
    cout << "3. Update Item" << endl;
    cout << "4. Search for Item" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

// Function to add an item to the inventory
void addItem(vector<InventoryItem> &inventory)
{
    InventoryItem newItem;
    cout << "Enter item name: ";
    cin >> newItem.name;
    cout << "\nEnter item ID: ";
    cin >> newItem.id;
    cout << "\nEnter item quantity: ";
    cin >> newItem.quantity;
    cout << "\nEnter item price: ";
    cin >> newItem.price;
    inventory.push_back(newItem);
    cout << "\nItem added to inventory." << endl;
}

// Function to remove an item from the inventory
void removeItem(std::vector<InventoryItem> &inventory)
{
    std::string itemName;
    int itemQuantity;

    std::cout << "\nEnter item name to remove quantity from: ";
    std::cin >> itemName;

    std::cout << "\nEnter item quantity to be removed: ";
    std::cin >> itemQuantity;

    // Find the item in the inventory by name
    for (InventoryItem& item : inventory)
    {
        if (item.name == itemName)
        {
            if (item.quantity >= itemQuantity)
            {
                item.quantity -= itemQuantity;
                cout << itemQuantity << " items removed from " << item.name << endl;
                cout << "\nRemaining quantity of " << item.name << " in the inventory: " << item.quantity << endl;
                return ;
            }
            else{
                cout << "\nError: Not enough quanitty available for " << item.name << endl;
                return;
            }
        }
    }
    // If the item with the specified name is not found
    std::cout << "\nError: Item with name " << itemName << " not found in the inventory" << std::endl;
}

// Function to display inventory
void displayInventory(const vector<InventoryItem> &inventory)
{
    if (inventory.empty())
    {
        cout << "\nInventory is empty.\n" << endl;
        return;
    }

    cout << "\nInventory Items:\n" << endl;
    for (const InventoryItem &item : inventory)
    {
        cout << "Name: " << item.name << " | ID: " << item.id << " | Quantity: " << item.quantity << " | Price: $" << item.price << endl;
    }
}

int main()
{
    cout << "\n\nProject Name: Inventory System for retailers\n";
    vector<InventoryItem> inventory;

    int choice;
    do
    {
        choice = displayMenu();

        switch (choice)
        {
        case 1:
            addItem(inventory);
            break;
        case 2:
            // Implement remove item functionality
            removeItem(inventory);
            break;
        case 3:
            // Implement update item functionality
            break;
        case 4:
            displayInventory(inventory);
            break;
        case 5:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 5);

    cout << "\n\n";
    return 0;
}
/*
Simple example of how you can implement the project setup and the basic structure of a C++
inventory system program. Please note that this is a basic starting point, and you can expand upon it as you
progress through the project:

In this code:

We define a struct called InventoryItem to represent an inventory item, with attributes like name, ID, quantity,
and price.

The displayMenu function displays a simple menu and returns the user's choice.

The addItem function allows the user to add an item to the inventory. You can expand this function to validate
user input and add error handling as needed.

The displayInventory function displays the current inventory items.

This code is a starting point for your project. You can continue by implementing the missing functionality
(e.g., removing and updating items), data storage (e.g., saving to and loading from files), error handling,
and any other features you want to add to your inventory system.
*/