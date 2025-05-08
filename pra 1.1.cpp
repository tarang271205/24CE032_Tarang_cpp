#include <iostream>
using namespace std;

class BankAccount {
    double balance = 0;

public:
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful! New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful! New balance: " << balance << endl;
        } else {
            cout << "Error: Either invalid amount or insufficient balance!" << endl;
        }
    }

    void checkBalance() {
        cout << "Account Balance: " << balance << endl;
    }
};

int main() {
    BankAccount account;
    int choice;
    double amount;

    while (true) {
        cout << "\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter deposit amount: ";
            cin >> amount;
            account.deposit(amount);
        }
        else if (choice == 2) {
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            account.withdraw(amount);
        }
        else if (choice == 3) {
            account.checkBalance();
        }
        else if (choice == 4) {
            cout << "Exiting..." << endl;
            break;
        }
        else {
            cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}
