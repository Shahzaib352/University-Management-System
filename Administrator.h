#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <iostream>
#include <string>
#include "Authenticator.h" // Includes SinglyLinkedList and Account

using namespace std;

class Administrator {
private:
    string adminUsername;
    string adminPassword;  // Ideally hashed for security

public:
    // Constructor
    Administrator(const string& username, const string& password) : adminUsername(username), adminPassword(password) {}

    // Login function: Verifies admin credentials
    bool login(const string& inputUsername, const string& inputPassword) {
        if (inputUsername == adminUsername && inputPassword == adminPassword) {
            cout << "Admin login successful!" << endl;
            return true;
        }
        cout << "Invalid login credentials." << endl;
        return false;
    }

    // Change adminPassword function (for admin)
    void changeadminPassword(const string& newPassword) {
        adminPassword = newPassword; // In real-world applications, hash the adminPassword
        cout << "Password changed successfully for Admin!" << endl;
    }

    // Create a new user account (student, professor, etc.)
    void createAccount(Authenticator& auth, const string& newUsername, const string& newPassword) {
        auth.createAccount(newUsername, newPassword);
        cout << "Account created successfully for: " << newUsername << endl;
    }

    // Delete an existing user account
    void deleteAccount(Authenticator& auth, const string& username) {
        if (auth.deleteAccount(username)) {
            cout << "Account deleted successfully for: " << username << endl;
        } else {
            cout << "Account not found!" << endl;
        }
    }

    // Update user information (e.g., adminPassword)
    void updateAccount(Authenticator& auth, const string& username, const string& newPassword) {
        auth.changeadminPassword(username, newPassword);
        cout << "Account updated successfully for: " << username << endl;
    }

    // View all user accounts
    void viewAllAccounts(Authenticator& auth) {
        cout << "List of all accounts:" << endl;
        auth.viewAllAccounts(); // Calls Authenticator to display accounts
    }

    // Search for an account
    void searchAccount(Authenticator& auth, const string& username) {
        if (auth.findAccount(username)) {
            cout << "Account found: " << username << endl;
        } else {
            cout << "Account not found!" << endl;
        }
    }
};

#endif
