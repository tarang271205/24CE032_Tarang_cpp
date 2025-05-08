#include<iostream>
using namespace std;

// Fuel Class
class Fuel {
public:
    string fuelType;
    Fuel(string f) {
        fuelType = f;
    }
    void displayFuel() {
        cout << "Fuel Type: " << fuelType << endl;
    }
};

// Brand Class
class Brand {
public:
    string brandName;
    Brand(string b) {
        brandName = b;
    }
    void displayBrand() {
        cout << "Brand Name: " << brandName << endl;
    }
};

// Car Class - Inheriting Fuel and Brand
class Car : public Fuel, public Brand {
public:
    Car(string f, string b) : Fuel(f), Brand(b) {}

    void displayCar() {
        displayBrand();
        displayFuel();
    }
};

int main() {
    Car* cars[100]; // Array of pointers to Car
    int count = 0;
    int choice;
    string brand, fuel;

    do {
        cout << "\n1. Add Car\n2. Show All Cars\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Brand: ";
            cin >> brand;
            cout << "Enter Fuel Type: ";
            cin >> fuel;

            cars[count] = new Car(fuel, brand);
            cout << "Car Added!\n";
            count++;
        }
        else if (choice == 2) {
            if (count == 0)
                cout << "No cars added yet.\n";
            else {
                for (int i = 0; i < count; i++) {
                    cout << "\nCar " << i + 1 << ":\n";
                    cars[i]->displayCar();
                }
            }
        }

    } while (choice != 0);

    cout << "\nExiting System...\n";
    return 0;
}
