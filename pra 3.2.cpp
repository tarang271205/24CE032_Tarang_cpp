#include <iostream>
using namespace std;

int sumRecursive(int arr[], int n) {
    if (n == 0)
        return 0;
    return arr[n - 1] + sumRecursive(arr, n - 1);
}

int sumIterative(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Sum using recursion: " << sumRecursive(arr, n) << endl;
    cout << "Sum using iteration: " << sumIterative(arr, n) << endl;

    return 0;
}
