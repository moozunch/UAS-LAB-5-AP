#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int loginOption () {
    system("CLS");
    int login;
    cout << "=========== My Travel ===========\n";
    cout << "1. Admin\n";
    cout << "2. User\n";
    cout << "3. Exit\n";
    cout << "Choose an option as login : ";
    cin >> login;
    return login;
}

bool containsDigit(const string &checkValue) {
    for (const char c : checkValue){
        if (isdigit(c)){
            return true;
        }
    }

    return false;
}

bool statusLogin(const char *username, const char *savedUsername, const char *password, const char *savedPassword) {
    if(strcasecmp(username, savedUsername) == 0 && strcmp(password, savedPassword) == 0){
        return true;
    }

    return false;
}

bool timeValidation(const string &checkValue) {
    for (int i = 0; i < checkValue.size(); i++){
        if (i != 2){
            if (isdigit(checkValue[i])){
                return false;
            }
        } else {
            continue;
        }
    }

    return true;
}