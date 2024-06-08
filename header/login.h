#include <iostream>
using namespace std;

int loginOption () {
    int login;
    cout << "=========== My Travel ===========\n";
    cout << "1. Admin\n";
    cout << "2. User\n";
    cout << "3. Exit\n";
    cout << "Pilih Opsi Login anda: ";
    cin >> login;
    return login;
}