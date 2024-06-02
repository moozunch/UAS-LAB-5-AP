#include <iostream>
using namespace std;


int main() {
    string username, password;
    cout << "Login" << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (username == "admin" && password == "admin123") {

        int option;
        do {
            cout << "Options:" << endl;
            cout << "1) Buy Ticket" << endl;
            cout << "2) View Ticket History" << endl;
            cout << "3) Exit" << endl;
            cout << "Choose an option: ";
            cin >> option;

            switch (option) {
                case 1: {
                    
                }
                case 2: {
                    
                }
                case 3: {
                    cout << "Exiting..." << endl;
                    break;
                }
                default: {
                    cout << "Invalid option!" << endl;
                    break;
                }
            }
        } while (option != 3);
    } else {
        cout << "Invalid username or password!" << endl;
    }

    return 0;
}