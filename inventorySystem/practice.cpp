#include <iostream>
#include <vector>

using namespace std;

// Define the structure of an inventory item
struct InventoryItem
{
    string name;
    string description;
    string sku;
    string barcode;
    int quantityInStock;
    string location;
};

// Create a vector to store the inventory items
vector<InventoryItem> inventoryItems;

// Function to add an inventory item
void AddInventoryItem(InventoryItem item)
{
    inventoryItems.push_back(item);
}

// Function to remove an inventory item
void RemoveInventoryItem(string sku)
{
    for (int i = 0; i < inventoryItems.size(); i++)
    {
        if (inventoryItems[i].sku == sku)
        {
            inventoryItems.erase(inventoryItems.begin() + i);
            break;
        }
    }
}

// Function to update an inventory item
void UpdateInventoryItem(string sku, int quantityInStock)
{
    for (int i = 0; i < inventoryItems.size(); i++)
    {
        if (inventoryItems[i].sku == sku)
        {
            inventoryItems[i].quantityInStock = quantityInStock;
            break;
        }
    }
}

// Function to generate a report of all inventory items
void GenerateInventoryReport()
{
    cout << "Inventory Report" << endl;
    cout << "----------------" << endl;

    for (int i = 0; i < inventoryItems.size(); i++)
    {
        cout << inventoryItems[i].name << ": " << inventoryItems[i].quantityInStock << endl;
    }
}

int main()
{
    // Add some inventory items
    InventoryItem item1 = {"Apple", "A delicious red fruit", "12345", "67890", 10, "Shelf A1"};
    InventoryItem item2 = {"Banana", "A yellow fruit", "54321", "09876", 5, "Shelf A2"};

    AddInventoryItem(item1);
    AddInventoryItem(item2);

    // Generate an inventory report
    GenerateInventoryReport();

    // Remove an inventory item
    RemoveInventoryItem("12345");

    // Update an inventory item
    UpdateInventoryItem("54321", 2);

    // Generate an inventory report
    GenerateInventoryReport();

    return 0;
}
