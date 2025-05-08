#include<iostream>
using namespace std;

class Person {
public:
    string Name;
    int Age;

    Person(string n, int a) : Name(n), Age(a) {}

    void Display() {
        cout << "Name: " << Name << ", Age: " << Age;
    }
};

class Employee : public Person {
public:
    float ID;

    Employee(string n, int a, float id) : Person(n, a), ID(id) {}

    void Display() {
        Person::Display();
        cout << ", Employee ID: " << ID << endl;
    }
};

class Manager : public Employee {
public:
    string Department;

    Manager(string n, int a, float id, string dept) : Employee(n, a, id), Department(dept) {}

    void Display() {
        Employee::Display();
        cout << ", Department: " << Department << endl;
    }
};

int main() {
    int choice;
    string name, dept;
    int age;
    float id;

    do {
        cout << "\n1. Add Employee\n2. Add Manager\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1) {
            cout << "\nEnter Employee Details:\n";
            cout << "Name: "; cin >> name;
            cout << "Age: "; cin >> age;
            cout << "Employee ID: "; cin >> id;

            Employee e(name, age, id);
            e.Display();
        }
        else if(choice == 2) {
            cout << "\nEnter Manager Details:\n";
            cout << "Name: "; cin >> name;
            cout << "Age: "; cin >> age;
            cout << "Employee ID: "; cin >> id;
            cout << "Department: "; cin >> dept;

            Manager m(name, age, id, dept);
            m.Display();
        }
        else if(choice == 0) {
            break;
        }
        else {
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
