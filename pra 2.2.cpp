#include <iostream>
using namespace std;

class Student {
    int rollNo, m1, m2, m3;
    float avg;
    string name;

    void calculateAverage() {
        avg = (m1 + m2 + m3) / 3.0;
    }

public:
    void setData(int r = 0, string n = "Test", int a = 0, int b = 0, int c = 0) {
        rollNo = r;
        name = n;
        m1 = a;
        m2 = b;
        m3 = c;
        calculateAverage();
    }

    void showData() {
        cout << "\nRoll No: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nMarks: " << m1 << ", " << m2 << ", " << m3;
        cout << "\nAverage: " << avg << endl;
    }
};

int main() {
    Student s[5];
    int r, a, b, c;
    string n;
    int ch;

    cout << "\nEnter details for 5 students:\n";

    for (int i = 0; i < 5; i++) {
        cout << "\nDo you want to enter data for Student " << i + 1 << "? (1 = Yes, 0 = No): ";
        cin >> ch;

        if (ch == 1) {
            cout << "Enter Roll No: ";
            cin >> r;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, n);
            cout << "Enter 3 subject marks: ";
            cin >> a >> b >> c;
            s[i].setData(r, n, a, b, c);
        } else {
            s[i].setData(); // default
        }
    }

    cout << "\n\nDisplaying student details:\n";
    for (int i = 0; i < 5; i++) {
        s[i].showData();
    }

    return 0;
}
