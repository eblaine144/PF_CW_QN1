#include <iostream>
#include <map>
#include <string>
using namespace std;

// Global variables to store account information
map<string, string> accounts; // To store user id and password
map<string, double> balances; // To store user id and balance

// Function prototypes
void createAccount();
bool login(string &userId);
void atmMenu(string &userId);

int main() {
    char choice;
    string userId;

    cout << "Hi! Welcome to the ATM Machine!\n";

    while (true) {
        cout << "\nPlease select an option from the menu below:\n";
        cout << "1 -> Login\n";
        cout << "c -> Create New Account\n";
        cout << "q -> Quit\n";
        cout << "> ";
        cin >> choice;

        if (choice == '1') {
            if (login(userId)) {
                atmMenu(userId);
            } else {
                cout << "*** LOGIN FAILED! ***\n";
            }
        } else if (choice == 'c') {
            createAccount();
        } else if (choice == 'q') {
            cout << "Thank you for using the ATM Machine. Goodbye!\n";
            break;
        } else {
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}

// Function to create a new account
void createAccount() {
    string userId, password;
    cout << "Please enter your user id: ";
    cin >> userId;
    cout << "Please enter your password: ";
    cin >> password;

    // Check if account already exists
    if (accounts.find(userId) != accounts.end()) {
        cout << "Account with this user id already exists!\n";
    } else {
        accounts[userId] = password;
        balances[userId] = 0.0; // Initialize balance to 0
        cout << "Thank You! Your account has been created!\n";
    }
}

// Function to log in to an existing account
bool login(string &userId) {
    string password;
    cout << "Please enter your user id: ";
    cin >> userId;
    cout << "Please enter your password: ";
    cin >> password;

    if (accounts.find(userId) != accounts.end() && accounts[userId] == password) {
        cout << "Access Granted!\n";
        return true;
    }
    return false;
}

// Function to display ATM menu after successful login
void atmMenu(string &userId) {
    char option;
    double amount;

    while (true) {
        cout << "\nd -> Deposit Money\n";
        cout << "w -> Withdraw Money\n";
        cout << "r -> Request Balance\n";
        cout << "q -> Quit\n";
        cout << "> ";
        cin >> option;

        if (option == 'd') {
            cout << "Amount of deposit: $";
            cin >> amount;
            if (amount > 0) {
                balances[userId] += amount;
                cout << "Deposit successful. Your balance is now $" << balances[userId] << ".\n";
            } else {
                cout << "Invalid deposit amount.\n";
            }
        } else if (option == 'w') {
            cout << "Amount of withdrawal: $";
            cin >> amount;
            if (amount > 0 && amount <= balances[userId]) {
                balances[userId] -= amount;
                cout << "Withdrawal successful. Your balance is now $" << balances[userId] << ".\n";
            } else {
                cout << "Invalid or insufficient balance for withdrawal.\n";
            }
        } else if (option == 'r') {
            cout << "Your balance is $" << balances[userId] << ".\n";
        } else if (option == 'q') {
            cout << "Logging out. Thank you for using the ATM Machine!\n";
            break;
        } else {
            cout << "Invalid option. Please try again.\n";
        }
    }
}