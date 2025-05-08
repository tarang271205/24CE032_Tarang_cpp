#include<iostream>
using namespace std;

class Grading {
protected:
    float percent;
    virtual void CalculateGrade() = 0;
public:
    virtual void DisplayGrade() = 0;
};

class UgGrading : public Grading {
private:
    int m1, m2, m3;

    void CalculateGrade() override {
        percent = (m1 + m2 + m3) / 1.5;
    }

public:
    void InputMarks() {
        cout << "\nEnter Marks for 3 Subjects (Out of 50): ";
        cin >> m1 >> m2 >> m3;
        CalculateGrade();
    }

    void DisplayGrade() override {
        cout << "\nPercentage: " << percent << "%";
        if (percent >= 45) cout << "\nGrade: O (Excellent)";
        else if (percent >= 40) cout << "\nGrade: I (Good)";
        else cout << "\nGrade: F (Fail)";
    }
};

class PgGrading : public Grading {
private:
    int m1, m2;

    void CalculateGrade() override {
        percent = (m1 + m2) / 2;
    }

public:
    void InputMarks() {
        cout << "\nEnter Marks for 2 Subjects (Out of 100): ";
        cin >> m1 >> m2;
        CalculateGrade();
    }

    void DisplayGrade() override {
        cout << "\nPercentage: " << percent << "%";
        if (percent >= 95) cout << "\nGrade: O (Excellent)";
        else if (percent >= 85) cout << "\nGrade: A (Very Good)";
        else if (percent >= 70) cout << "\nGrade: B (Good)";
        else cout << "\nGrade: F (Fail)";
    }
};

int main() {
    int nUG, nPG;

    cout << "Enter number of UG students: ";
    cin >> nUG;
    cout << "Enter number of PG students: ";
    cin >> nPG;

    UgGrading ugStudents[nUG];
    PgGrading pgStudents[nPG];

    cout << "\nEnter marks for UG students:\n";
    for (int i = 0; i < nUG; i++) {
        cout << "Student " << i + 1 << ": ";
        ugStudents[i].InputMarks();
        ugStudents[i].DisplayGrade();
    }

    cout << "\nEnter marks for PG students:\n";
    for (int i = 0; i < nPG; i++) {
        cout << "Student " << i + 1 << ": ";
        pgStudents[i].InputMarks();
        pgStudents[i].DisplayGrade();
    }

    return 0;
}
