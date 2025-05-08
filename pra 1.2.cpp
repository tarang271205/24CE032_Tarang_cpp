#include <iostream>
using namespace std;

class Product {
public:
    int productID;
    string name;
    int quantity;
    double price;

    void setDetails(int id, string n, int q, double p) {
        productID = id;
        name = n;
        quantity = q;
        price = p;
    }

    void updateQuantity(int newQuantity) {
        quantity = newQuantity;
    }

    double calculateTotalValue() const {
        return quantity * price;
    }

    void displayProduct() const {
        cout << "ID: " << productID << ", Name: " << name << ", Quantity: " << quantity << ", Price: " << price << endl;
    }
};

class Inventory {
private:
    Product products[10];  // Fixed size array of 10 products
    int productCount = 0;

public:
    void addProduct() {
        if (productCount < 10) {
            Product p;
            int id, quantity;
            string name;
            double price;

            cout << "Enter Product ID, Name, Quantity, and Price: ";
            cin >> id >> name >> quantity >> price;
            p.setDetails(id, name, quantity, price);
            products[productCount++] = p;
        } else {
            cout << "Inventory full. Cannot add more products." << endl;
        }
    }

    void updateProductQuantity() {
        int id, newQuantity;
        cout << "Enter Product ID and new Quantity: ";
        cin >> id >> newQuantity;

        for (int i = 0; i < productCount; i++) {
            if (products[i].productID == id) {
                products[i].updateQuantity(newQuantity);
                cout << "Product quantity updated successfully!" << endl;
                return;
            }
        }
        cout << "Product not found!" << endl;
    }

    void calculateTotalInventoryValue() {
        double totalValue = 0;
        for (int i = 0; i < productCount; i++) {
            totalValue += products[i].calculateTotalValue();
        }
        cout << "Total Inventory Value: " << totalValue << endl;
    }

    void displayInventory() {
        for (int i = 0; i < productCount; i++) {
            products[i].displayProduct();
        }
    }
};

int main() {
    Inventory storeInventory;
    int choice;

    do {
        cout << "\n1. Add Product\n2. Update Quantity\n3. Display Inventory\n4. Calculate Total Value\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                storeInventory.addProduct();
                break;
            case 2:
                storeInventory.updateProductQuantity();
                break;
            case 3:
                storeInventory.displayInventory();
                break;
            case 4:
                storeInventory.calculateTotalInventoryValue();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
