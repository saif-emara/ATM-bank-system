#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int main() {
    double data[1] = {50000}; // Updated balance
    int act[2], pwd, choice;
    char r;

    cout << "\n=== Welcome to Eru's ATM ===\n";
    cout << "Please enter your secret password: ";

    while (cin >> pwd, pwd != 552005) {
        cout << "Incorrect! Try again? (y/n): ";
        cin >> r;
        if (r == 'n' || r == 'N') {
            cout << "Goodbye!\n";
            return 0;
        }
        cout << "Password: ";
    }

    cout << "Access Granted! Enjoy your session with Eru's ATM.\n";

    while (true) {
        cout << "\n=============================\n";
        cout << " 1. Check Balance\n 2. Withdraw Money\n 3. Deposit Money\n 4. Exit\n";
        cout << "=============================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << ">> Your balance is: $" << data[0] << "\n";
                break;
            case 2:
                cout << ">> Enter amount to withdraw: $";
                cin >> act[1];
                if (act[1] > data[0])
                    cout << "!! Not enough balance. Try again.\n";
                else {
                    data[0] -= act[1];
                    cout << ">> Dispensing cash...\n";
                    for (int i = 1; i <= 5; ++i) {
                        cout << "Counting bill " << i << "...\n";
                        this_thread::sleep_for(chrono::milliseconds(500));
                    }
                    cout << ">> Please take your cash: $" << act[1] << endl;
                    cout << ">> New balance: $" << data[0] << "\n";
                }
                break;
            case 3:
                cout << ">> Enter your cash in the ATM: $";
                cin >> act[0];
                data[0] += act[0];
                cout << ">> Deposit successful! New balance: $" << data[0] << "\n";
                break;
            case 4:
                cout << "Thank you for using Eru's ATM. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}