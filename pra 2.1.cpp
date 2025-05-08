#include <iostream>
using namespace std;

class Rectangle {
private:
    int length, width;

public:
    void set(int l, int w) {
        length = l;
        width = w;
    }

    int area() const {
        return length * width;
    }

    int perimeter() const {
        return 2 * (length + width);
    }

    void display() const {
        cout << "Length: " << length << ", Width: " << width << endl;
        cout << "Area: " << area() << " sq. units, Perimeter: " << perimeter() << " units" << endl;
    }
};

int main() {
    Rectangle rectangles[10];
    int count = 0, choice;

    do {
        cout << "\nMenu:\n"
             << "1. Add a new Rectangle\n"
             << "2. Update an existing Rectangle\n"
             << "3. View all Rectangles\n"
             << "0. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                if (count >= 10) {
                    cout << "Maximum number of rectangles reached.\n";
                } else {
                    int l, w;
                    cout << "Enter length and width for Rectangle " << count + 1 << ": ";
                    cin >> l >> w;
                    rectangles[count].set(l, w);
                    cout << "Rectangle " << count + 1 << " added!\n";
                    count++;
                }
                break;
            }

            case 2: {
                if (count == 0) {
                    cout << "No rectangles to update.\n";
                } else {
                    int index;
                    cout << "Enter the Rectangle number to update (1 to " << count << "): ";
                    cin >> index;

                    if (index < 1 || index > count) {
                        cout << "Invalid Rectangle number.\n";
                    } else {
                        int l, w;
                        cout << "Enter new length and width: ";
                        cin >> l >> w;
                        rectangles[index - 1].set(l, w);
                        cout << "Rectangle " << index << " updated!\n";
                    }
                }
                break;
            }

            case 3: {
                if (count == 0) {
                    cout << "No rectangles to display.\n";
                } else {
                    for (int i = 0; i < count; i++) {
                        cout << "\nRectangle " << i + 1 << " details:\n";
                        rectangles[i].display();
                    }
                }
                break;
            }

            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
