#include <iostream>
using namespace std;

class Account {
    int accNum;
    string name;
    float balance;

    static int count;

public:
    Account() {
        accNum = 0;
        name = "";
        balance = 0;
    }

    void create(int num, string n, float bal) {
        accNum = num;
        name = n;
        balance = bal;
        count++;
    }

    void display() {
        cout << "\nName: " << name;
        cout << "\nAccount Number: " << accNum;
        cout << "\nBalance: " << balance;
    }

    int getAccNum() {
        return accNum;
    }

    void transfer(Account &other, float amt) {
        if (balance >= amt) {
            balance -= amt;
            other.balance += amt;
        } else {
            cout << "\nNot enough balance!";
        }
    }

    static int getCount() {
        return count;
    }
};

int Account::count = 0;

int main() {
    int size = 100;
    Account* accounts = new Account[size];
    int total = 0;
    int choice;

    do {
        cout << "\n1. Add Account\n2. Transfer Money\n3. Show All Accounts\n0. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            int num;
            string name;
            float bal;
            cout << "Enter Account Number: ";
            cin >> num;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Balance: ";
            cin >> bal;

            accounts[total].create(num, name, bal);
            total++;
        }
        else if (choice == 2) {
            int from, to;
            float amt;
            cout << "Enter your Account Number: ";
            cin >> from;
            cout << "Enter Receiver Account Number: ";
            cin >> to;
            cout << "Enter Amount to Transfer: ";
            cin >> amt;

            Account *a = nullptr, *b = nullptr;
            for (int i = 0; i < total; i++) {
                if (accounts[i].getAccNum() == from)
                    a = &accounts[i];
                if (accounts[i].getAccNum() == to)
                    b = &accounts[i];
            }

            if (a && b) {
                a->transfer(*b, amt);
                cout << "\nTransfer Successful!";
            } else {
                cout << "\nAccount Not Found!";
            }
        }
        else if (choice == 3) {
            cout << "\nTotal Accounts: " << Account::getCount();
            for (int i = 0; i < total; i++) {
                cout << "\n\nAccount " << (i + 1);
                accounts[i].display();
            }
        }
    } while (choice != 0);

    delete[] accounts;
    return 0;
}
