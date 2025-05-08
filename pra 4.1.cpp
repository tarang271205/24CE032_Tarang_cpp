#include<iostream>
using namespace std;

class Shape {
private:
    float radius; // size(int)=4

protected:
    Shape(float r) { // constructor
        radius = r;
    }

    float GetRadius() {
        return radius; // to access private member after inheritance
    }
};

class Circle : private Shape {
private:
    float Area;

    void CalculateArea() { // utility function
        Area = 3.14159265 * GetRadius() * GetRadius();
    }

public:
    Circle(float r = 0) : Shape(r) {
        CalculateArea(); // derived class constructor
    }

    void DisplayData() {
        cout << "\nRadius: " << GetRadius() << " units";
        cout << "\nArea: " << Area << " sq. units";
    }
};

int main() {
    const int MAX_CIRCLES = 100; // Maximum number of circles
    Circle Circles[MAX_CIRCLES]; // Static array of circles
    int choice = 1, i = 0;
    float r = 0;

    while (choice == 1 || choice == 2) {
        cout << "\n\nCircle Management System Choices:\n1. Add Circle\n2. Display all Circles\n0. Exit System\n\nEnter Choice: ";
        cin >> choice; // choice-based system

        if (choice == 1) {
            if (i < MAX_CIRCLES) {
                cout << "\nEnter New Circle Radius: ";
                cin >> r;
                Circles[i] = Circle(r); // Add circle to array
                cout << "\nNew Circle added successfully!!\n\nDisplaying its details:-";
                Circles[i].DisplayData();
                i++;
            } else {
                cout << "\nCannot add more circles. Maximum limit reached.\n";
            }
        }
        else if (choice == 2) {
            cout << "\nDisplaying " << i << " circles' details:-";
            for (int j = 0; j < i; j++) {
                cout << "\n\nCircle " << j + 1 << " details:-";
                Circles[j].DisplayData();
            }
        }
        else
            break;
    }
    cout << "\n\nExiting System.....";

    return 0;
}
