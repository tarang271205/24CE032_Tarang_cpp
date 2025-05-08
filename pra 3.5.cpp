#include <iostream>
#include <string>
using namespace std;

int superDigit(long long n) {
    if (n < 10)
        return n;

    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n = n / 10;
    }

    return superDigit(sum);
}

int main() {
    string number;
    int repeat;

    cout << "Enter the number: ";
    cin >> number;
    cout << "Enter the repeat factor: ";
    cin >> repeat;

    long long total = 0;

    for (int i = 0; i < number.size(); i++) {
        total += number[i] - '0';
    }

    cout << "Sum of digits of the number: " << total << endl;

    total = total * repeat;
    cout << "Total after multiplication with repeat factor: " << total << endl;

    cout << "Super Digit: " << superDigit(total) << endl;

    return 0;
}
