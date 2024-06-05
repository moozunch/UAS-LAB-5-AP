#include <iostream>
#include <vector>
using namespace std;

struct Ticket{
    string name, destination, date;
};

class Buyer {
    private:
        vector<Ticket> tickets;

    public:
        void buyTicket(const Ticket &ticket) {
            system("CLS");
            tickets.emplace_back(ticket);
            cout << "Ticket Bought Succesfully!" << endl;
            system("PAUSE");
        }

        void displayTicketHistory() {
            system("CLS");
            if (tickets.empty()) {
                cout << "No Tickets Bought Yet!" << endl;
                system("PAUSE");
            } else {
                cout << "Booked Tickets:" << endl;

                for (const auto &ticket : tickets) {
                    cout << "Name           : " << ticket.name << endl;
                    cout << "Destination    : " << ticket.destination << endl;
                    cout << "Date           : " << ticket.date << endl;
                    cout << "------------------------" << endl;
                }
                system("PAUSE");
            }
        }
};

int main() {
    system("CLS");

    string username, password;
    
    cout << "Login" << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (username == "admin" && password == "admin123") {
        system("CLS");
        Buyer buyer;
        Ticket ticket;
        int option;

        do {
            system("CLS");
            cout << "Options:" << endl;
            cout << "1) Buy Ticket" << endl;
            cout << "2) View Ticket History" << endl;
            cout << "3) Exit" << endl;
            cout << "Choose an option: ";
            cin >> option;
            cin.ignore();

            switch (option) {
                case 1: {
                    cout << "Enter passenger name: ";
                    cin >> ticket.name;
                    cout << "Enter destination: ";
                    cin >> ticket.destination;
                    cout << "Enter date (YYYY-MM-DD): ";
                    cin >> ticket.date;

                    buyer.buyTicket(ticket);
                    break;
                }
                case 2: {
                    buyer.displayTicketHistory();
                    break;
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