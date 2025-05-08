#include<iostream>
using namespace std;

// Parent class: Common Bank Account
class BankAccount {
protected:
    int accountNumber;
    float balance;
    float history[100]; // Transaction history
    int historyIndex;

public:
    // Constructor
    BankAccount(int accNo, float bal) {
        accountNumber = accNo;
        balance = bal;
        historyIndex = 0;
        history[historyIndex++] = bal; // Save initial balance
    }

    // Destructor
    virtual ~BankAccount() {}

    // Deposit money
    void deposit(float amount) {
        balance += amount;
        history[historyIndex++] = balance;
    }

    // Withdraw money
    virtual bool withdraw(float amount) {
        if(amount <= balance) {
            balance -= amount;
            history[historyIndex++] = balance;
            return true;
        }
        return false;
    }

    // Undo last transaction
    void undoTransaction() {
        if(historyIndex > 1) {
            historyIndex--;
            balance = history[historyIndex - 1];
            cout << "Last transaction undone successfully.\n";
        } else {
            cout << "No transaction to undo.\n";
        }
    }

    // Show account details
    void showDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: Rs. " << balance << endl;
    }
};

// Child class: Savings Account
class SavingsAccount : public BankAccount {
    float interestRate;

public:
    SavingsAccount(int accNo, float bal, float rate) : BankAccount(accNo, bal) {
        interestRate = rate;
    }

    void showDetails() {
        BankAccount::showDetails();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

// Child class: Current Account
class CurrentAccount : public BankAccount {
    float overdraftLimit;

public:
    CurrentAccount(int accNo, float bal, float limit) : BankAccount(accNo, bal) {
        overdraftLimit = limit;
    }

    // Withdraw with overdraft
    bool withdraw(float amount) override {
        if(amount <= balance + overdraftLimit) {
            balance -= amount;
            history[historyIndex++] = balance;
            return true;
        }
        return false;
    }

    void showDetails() {
        BankAccount::showDetails();
        cout << "Overdraft Limit: Rs. " << overdraftLimit << endl;
    }
};

// Main program
int main() {
    SavingsAccount* savings = nullptr;
    CurrentAccount* current = nullptr;

    int choice, accNo;
    float bal, rate, limit, amount;

    while(true) {
        cout << "\n--- Simple Banking System ---" << endl;
        cout << "1. Create Savings Account" << endl;
        cout << "2. Create Current Account" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Withdraw" << endl;
        cout << "5. Undo Last Transaction" << endl;
        cout << "6. Show Account Details" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter Account Number: ";
                cin >> accNo;
                cout << "Enter Initial Balance: Rs. ";
                cin >> bal;
                cout << "Enter Interest Rate (%): ";
                cin >> rate;
                savings = new SavingsAccount(accNo, bal, rate);
                current = nullptr; // Only one account at a time
                break;

            case 2:
                cout << "Enter Account Number: ";
                cin >> accNo;
                cout << "Enter Initial Balance: Rs. ";
                cin >> bal;
                cout << "Enter Overdraft Limit: Rs. ";
                cin >> limit;
                current = new CurrentAccount(accNo, bal, limit);
                savings = nullptr;
                break;

            case 3:
                cout << "Enter Amount to Deposit: Rs. ";
                cin >> amount;
                if(savings) savings->deposit(amount);
                else if(current) current->deposit(amount);
                else cout << "No account found!" << endl;
                break;

            case 4:
                cout << "Enter Amount to Withdraw: Rs. ";
                cin >> amount;
                if((savings && savings->withdraw(amount)) || (current && current->withdraw(amount)))
                    cout << "Withdrawal successful." << endl;
                else
                    cout << "Not enough balance or no account!" << endl;
                break;

            case 5:
                if(savings) savings->undoTransaction();
                else if(current) current->undoTransaction();
                else cout << "No account found!" << endl;
                break;

            case 6:
                if(savings) savings->showDetails();
                else if(current) current->showDetails();
                else cout << "No account found!" << endl;
                break;

            case 0:
                delete savings;
                delete current;
                cout << "Thank you for using the Banking System!" << endl;
                return 0;

            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
}
