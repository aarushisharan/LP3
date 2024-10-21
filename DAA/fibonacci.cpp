#include <iostream>
using namespace std;

int fibRecur(int n) {
    if (n < 0) {
        cout << "Invalid input" << endl;
        return -1;
    }
    if (n <= 1)
        return n;

    return fibRecur(n - 1) + fibRecur(n - 2);
}

int fibIter(int n) {
    int prev1 = 0, prev2 = 1;
    int curr;
    if (n <= 1) {
        return n;
    }
    for (int i = 2; i <= n+1; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main() {
    int choice;
    cout << "----Welcome-----" << endl;
    cout << "----MENU-------" << endl;
    cout << "1. Iterative" << endl;
    cout << "2. Recursive" << endl;
    cout << "3. Exit" << endl;

    do {
        cout << "Enter the choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int n1;
                cout << "Enter the value of n: ";
                cin >> n1;
                int ans = fibIter(n1);
                cout << "Fibonacci number (Iterative): " << ans << endl;
                break;
            }

            case 2: {
                int n2;
                cout << "Enter the value of n: ";
                cin >> n2;
                int res = fibRecur(n2);
                cout << "Fibonacci number (Recursive): " << res << endl;
                break;
            }

            case 3:
                cout << "Exit Code...." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
