#include <iostream>
using namespace std;

class Account {
    int accNo;
    string name;
    float balance;

public:
    void create() {
        cout << "Enter Account Number: ";
        cin >> accNo;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Initial Balance: ";
        cin >> balance;
        cout << "Account Created! Account No: " << accNo << endl;
    }

    void deposit() {
        float amount;
        cout << "Enter Amount to Deposit: ";
        cin >> amount;
        balance += amount;
        cout << "Deposited " << amount << " Rs. New Balance: " << balance << endl;
    }

    void withdraw() {
        float amount;
        cout << "Enter Amount to Withdraw: ";
        cin >> amount;
        if (balance - amount >= 1000) {
            balance -= amount;
            cout << "Withdrawn " << amount << " Rs. New Balance: " << balance << endl;
        } else {
            cout << "Minimum balance of Rs.1000 required!\n";
        }
    }

    void show() {
        cout << "\nAccount No: " << accNo << "\nName: " << name << "\nBalance: " << balance << endl;
    }
};

int main() {
    Account acc;
    int choice;

    do {
        cout << "\n1.Create Account  2.Deposit  3.Withdraw  4.Show Account  0.Exit\nChoose option: ";
        cin >> choice;

        if (choice == 1) {
            acc.create();
        }
        else if (choice == 2) {
            acc.deposit();
        }
        else if (choice == 3) {
            acc.withdraw();
        }
        else if (choice == 4) {
            acc.show();
        }

    } while (choice != 0);

    cout << "Exiting the system...\n";
    return 0;
}
