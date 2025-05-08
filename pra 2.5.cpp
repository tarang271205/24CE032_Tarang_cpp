#include <iostream>
using namespace std;

class LoanMaster {
    int loanID;
    string name;
    float principal;
    float annualRate;
    int months;
    float emi;
    float totalAmount;
    float totalInterest;

public:
    void getData() {
        cout << "\nEnter Loan ID: ";
        cin >> loanID;

        cout << "Enter Name (One Word): ";
        cin >> name;

        cout << "Enter Principal Amount: ";
        cin >> principal;

        cout << "Enter Annual Interest Rate (%): ";
        cin >> annualRate;

        cout << "Enter Tenure (in months): ";
        cin >> months;

        float R = annualRate / (12 * 100);
        float temp = 1;

        for (int i = 0; i < months; i++) {
            temp = temp * (1 + R);
        }

        emi = (principal * R * temp) / (temp - 1);
        totalAmount = emi * months;
        totalInterest = totalAmount - principal;
    }

    void showData() {
        cout << "\nLoan ID          : " << loanID;
        cout << "\nName             : " << name;
        cout << "\nPrincipal Amount : " << principal;
        cout << "\nInterest Rate    : " << annualRate << "%";
        cout << "\nTenure (months)  : " << months;
        cout << "\nMonthly EMI      : " << emi;
        cout << "\nTotal Interest   : " << totalInterest;
        cout << "\nTotal Payable    : " << totalAmount;
    }
};

int main() {
    LoanMaster loans[10];
    int count = 0;
    int choice;

    do {
        cout << "\n\nLoan Management System";
        cout << "\n1. Add New Loan";
        cout << "\n2. Show All Loan Summaries";
        cout << "\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1 && count < 10) {
            loans[count].getData();
            cout << "\nLoan Added Successfully!";
            loans[count].showData();
            count++;
        } 
        else if (choice == 2) {
            if (count == 0) {
                cout << "\nNo loans added yet!";
            } else {
                for (int i = 0; i < count; i++) {
                    cout << "\n\nLoan " << i + 1 << " Summary:";
                    loans[i].showData();
                }
            }
        }

    } while (choice != 0);

   
    return 0;
}
