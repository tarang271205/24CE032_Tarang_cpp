#include <iostream>
using namespace std;

class Item {
    int id;
    string name;
    float price;
    int quantity;

public:
    void create() {
        cout << "Enter Item ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    void addStock() {
        int q;
        cout << "Enter Quantity to Add: ";
        cin >> q;
        quantity += q;
    }

    void sell() {
        int q;
        cout << "Enter Quantity to Sell: ";
        cin >> q;
        if (q <= quantity) {
            quantity -= q;
        } else {
            cout << "Not enough stock!\n";
        }
    }

    void show() {
        cout << "\nID: " << id << " | Name: " << name << " | Price: " << price << " | Quantity: " << quantity;
    }

    int getId() {
        return id;
    }
};

int main() {
    Item items[10];
    int count = 0, choice, id;

    do {
        cout << "\n\n1.Add Item  2.Add Stock  3.Sell Item  4.Show All  0.Exit\nEnter Choice: ";
        cin >> choice;

        if (choice == 1 && count < 10) {
            items[count].create();
            count++;
        } 
        else if (choice == 2 || choice == 3) {
            cout << "Enter Item ID: ";
            cin >> id;
            for (int i = 0; i < count; i++) {
                if (items[i].getId() == id) {
                    if (choice == 2)
                        items[i].addStock();
                    else
                        items[i].sell();
                    break;
                }
            }
            cout << "Item not found!";
        } 
        else if (choice == 4) {
            for (int i = 0; i < count; i++)
                items[i].show();
        }

    } while (choice != 0);

    cout << "\nExiting system...\n";
    return 0;
}
