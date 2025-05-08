#include <iostream>
using namespace std;

class Employee {
    string name;
    int age;
    float basicSalary;
    float bonus;

    inline float calculateTotalSalary() {
        return basicSalary + bonus;
    }

public:
    Employee(string n, int a, float b, float bon = 10000) {
        name = n;
        age = a;
        basicSalary = b;
        bonus = bon;
    }

    void displayDetails() {
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nBasic Salary: " << basicSalary;
        cout << "\nBonus: " << bonus;
        cout << "\nTotal Salary: " << calculateTotalSalary();
    }
};

int main() {
    string name;
    int age;
    float basicSalary, bonus;
    char continueInput = 'y';

    while (continueInput == 'y' || continueInput == 'Y') {
        cout << "\nEnter Employee Name: ";
        cin >> name;

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Basic Salary: ";
        cin >> basicSalary;

        cout << "Do you want to enter a custom bonus? (y/n): ";
        cin >> continueInput;

        Employee emp(name, age, basicSalary);

        if (continueInput == 'y' || continueInput == 'Y') {
            cout << "Enter Custom Bonus Amount: ";
            cin >> bonus;
            emp = Employee(name, age, basicSalary, bonus);
        }

        emp.displayDetails();

        cout << "\nDo you want to add another employee? (y/n): ";
        cin >> continueInput;
    }

    return 0;
}
