#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Product {
public:
  string name;
  double price;

  Product(string name, double price) {
    this->name = name;
    this->price = price;
  }
};

class Location {
public:
  string name;
  int capacity;

  Location(string name, int capacity) {
    this->name = name;
    this->capacity = capacity;
  }
};

class InventoryItem {
public:
  shared_ptr<Product> product;
  shared_ptr<Location> location;
  int quantity;

  InventoryItem(shared_ptr<Product> product, shared_ptr<Location> location, int quantity) {
    this->product = product;
    this->location = location;
    this->quantity = quantity;
  }
};

class Inventory {
public:
  vector<shared_ptr<InventoryItem>> items;

  void addProduct(shared_ptr<Product> product, shared_ptr<Location> location, int quantity) {
    shared_ptr<InventoryItem> item = make_shared<InventoryItem>(product, location, quantity);
    items.push_back(item);
  }

  void updateQuantity(shared_ptr<Product> product, shared_ptr<Location> location, int quantity) {
    for (auto item : items) {
      if (item->product == product && item->location == location) {
        item->quantity += quantity;
        break;
      }
    }
  }

  void removeProduct(shared_ptr<Product> product, shared_ptr<Location> location, int quantity) {
    for (auto item = items.begin(); item != items.end(); ++item) {
      if ((*item)->product == product && (*item)->location == location) {
        items.erase(item);
        break;
      }
    }
  }

  void generateReport() {
    cout << "Inventory Report" << endl;
    cout << "----------------" << endl;

    for (auto item : items) {
      cout << item->product->name << ": " << item->quantity << endl;
    }
  }
};

int main() {
  Inventory inventory;

  shared_ptr<Product> product1 = make_shared<Product>("Product 1", 10.00);
  shared_ptr<Product> product2 = make_shared<Product>("Product 2", 20.00);

  shared_ptr<Location> location1 = make_shared<Location>("Warehouse 1", 100);
  shared_ptr<Location> location2 = make_shared<Location>("Warehouse 2", 200);

  inventory.addProduct(product1, location1, 50);
  inventory.addProduct(product2, location2, 100);

  inventory.generateReport();

  return 0;
}
