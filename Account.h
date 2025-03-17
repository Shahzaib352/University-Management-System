#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<iostream>
#include<string>
#include"LinkedList.h"
#include <algorithm>  // For any_of
#include <cctype>     // For isupper, islower, isdigit, ispunct

using namespace std;

class Account{
    private:
    // Attributes
    string username;
    string password;   // use hash concepts for security purposes
    string role;

    public:
    // constructor
    Account() : username(""), password("") {}  // Default 
    Account(string initial_username) : username(initial_username) {}
    Account(string initial_username, string initial_password) : username(initial_username), password(initial_password) {}
    Account(string initial_username, string initial_password, string initial_role) : username(initial_username), password(initial_password), role(initial_role) {}

    // Methods
    void setUsername(const string& newUsername){username = newUsername;}
    void setPassword(const string& newPassword){password = newPassword;}
    

    string getUsername()const {return username;}
    string getPassword()const {return password;}
    string getRole()const {return role;}

    void displayAccounts()const{
        cout << "Username: " << username << endl << "Password: " << password << endl;
    }

    friend ostream& operator<<(ostream& os, const Account& account){
        os << "Username: " << account.username << endl << "Password: " << account.password <<endl;
        return os;
    }

    bool operator==(const Account& other)const {
        return username == other.username && password == other.password; 
    }

    bool operator==(const string& otherUsername)const {
        return username == otherUsername;
    }

    bool isValidPassword(const string& password) {
    return password.length() >= 8 &&
           any_of(password.begin(), password.end(), ::isupper) &&
           any_of(password.begin(), password.end(), ::islower) &&
           any_of(password.begin(), password.end(), ::isdigit) &&
           any_of(password.begin(), password.end(), ::ispunct);
    }
};

#endif