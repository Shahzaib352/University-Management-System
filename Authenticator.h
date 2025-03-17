#ifndef AUTHENTICATOR_H
#define AUTHRNTICATOR_H

#include<iostream>
#include<string>
#include"Account.h"
#include"LinkedList.h"
using namespace std;

class Authenticator{
    private:
    // Attributes
    SinglyLinkedList<Account> accounts;

    public:
    // Methods
    void createAccount(const string& newUsername, const string& newPassword){
        accounts.insert(Account(newUsername, newPassword));
        cout << "Account created successfully." << endl;   
    }

    bool login(const string& inputUsername, const string& inputPassword){
        Account target(inputUsername, inputPassword);  // Search by username and password
        if (accounts.find(target)) {
            cout << "Login successful!" << endl;
            return true;
        } else {
            cout << "Login failed! Wrong Username or Password." << endl;
            return false;
        }
    }

    void changePassword(const string& username, const string& newPassword) {
        Account target(username); // Search by username
        if (accounts.find(target)) {
            Account found = accounts.get(target);
            accounts.update(found, Account(username, newPassword)); // Update password
            cout << "Password updated successfully for: " << username << endl;
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void changePasswordByAdmin(const string& adminUsername, const string& adminPassword, const string& targetUsername, const string& newPassword) {
        // Verify if the adminUsername is an admin
        Account* adminAccount = accounts.find(Account(adminUsername, adminPassword));
        if (!adminAccount || adminAccount->getRole() != "Admin") {
            cout << "Access denied. Only admins can change passwords." << endl;
            return;
        }

        // Search for the target account
        Account* targetAccount = accounts.find(Account(targetUsername));
        if (targetAccount) {
            targetAccount->setPassword(newPassword);
            cout << "Password updated successfully for username: " << targetUsername << endl;
        } else {
            cout << "No account found with username: " << targetUsername << endl;
        }
    } 

    void viewAllAccounts() const {
    accounts.display(); // Assuming SinglyLinkedList has a display() method
    }

    bool findAccount(const string& username) {
        Account target(username); // Search using username
        return accounts.find(target);
    }

    bool deleteAccount(const string& username) {
        Account target(username); // Search by username
        if (accounts.find(target)) {
            accounts.remove(target);
            return true;
        }
        return false;
    }

};

#endif