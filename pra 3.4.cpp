#include <iostream>
using namespace std;

template <typename T>
class Collection {
private:
    T* elements;
    int count;

public:
    Collection() : elements(nullptr), count(0) {}

    void addElements() {
        cout << "Enter number of elements: ";
        cin >> count;
        elements = new T[count];
        cout << "Enter elements:\n";
        for (int i = 0; i < count; i++) {
            cin >> elements[i];
        }
    }

    void displayElements() {
        cout << "Collection elements: ";
        for (int i = 0; i < count; i++) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }

    void reverseElements() {
        for (int i = 0; i < count / 2; i++) {
            T temp = elements[i];
            elements[i] = elements[count - 1 - i];
            elements[count - 1 - i] = temp;
        }
    }

    T findLargestElement() {
        T largest = elements[0];
        for (int i = 1; i < count; i++) {
            if (elements[i] > largest) {
                largest = elements[i];
            }
        }
        return largest;
    }

    ~Collection() {
        delete[] elements;
    }
};

int main() {
    Collection<int> intCollection;
    Collection<float> floatCollection;
    Collection<char> charCollection;

    int choice;
    do {
        cout << "\n1. Add Elements\n2. Display Elements\n3. Reverse Elements\n4. Find Largest Element\n0. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1: {
            int type;
            cout << "Choose data type: 1. int 2. float 3. char: ";
            cin >> type;

            if (type == 1) intCollection.addElements();
            else if (type == 2) floatCollection.addElements();
            else if (type == 3) charCollection.addElements();
            break;
        }
        case 2:
            intCollection.displayElements();
            floatCollection.displayElements();
            charCollection.displayElements();
            break;
        case 3:
            intCollection.reverseElements();
            floatCollection.reverseElements();
            charCollection.reverseElements();
            break;
        case 4:
            cout << "Largest int: " << intCollection.findLargestElement() << endl;
            cout << "Largest float: " << floatCollection.findLargestElement() << endl;
            cout << "Largest char: " << charCollection.findLargestElement() << endl;
            break;
        default: break;
        }
    } while (choice != 0);

    return 0;
}
