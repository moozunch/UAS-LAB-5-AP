#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "header/login.h"

using namespace std;

struct User {
    string login;
    string username;
    string password;
};

struct Date {
    string day;
    string month;
    string year;
};

struct Ticket {
    string price;
    string departure;
    string destination;
    Date date;
    string time;
};

struct Todo {
    string task;
    bool done;
};

class LoginSystem {
private:
    vector<Ticket> tickets;

public:
    void addTicket(const Ticket& ticket) {
        tickets.push_back(ticket);
        cout << "Ticket added successfully!" << endl;
    }

    void deleteTicket(int index) {
        if (index >= 0 && index < tickets.size()) {
            tickets.erase(tickets.begin() + index);
            cout << "Ticket deleted successfully!" << endl;
        } else {
            cout << "Invalid ticket index!" << endl;
        }
    }

    void displayTickets() {
        if (tickets.empty()) {
            cout << "No tickets available!" << endl;
        } else {
            cout << "Tickets List:" << endl;
            for (int i = 0; i < tickets.size(); ++i) {
                cout << "------------------------" << endl;
                cout << "Ticket Index " << i << endl;
                cout << "From " << tickets[i].departure << " To " << tickets[i].destination << endl;
                cout << "Date: " << tickets[i].date.day << "/" << tickets[i].date.month << "/" << tickets[i].date.year << endl;
                cout << "Time: " << tickets[i].time << endl;
                cout << "Price: Rp" << tickets[i].price << endl;
                cout << "------------------------" << endl;
            }
        }
    }

    Ticket getTicket(int index) {
        if (index >= 0 && index < tickets.size()) {
            return tickets[index];
        } else {
            cout << "Invalid ticket index!" << endl;
            return Ticket{};
        }
    }
};

class TicketBookingSystem {
private:
    vector<Ticket> bookedTickets;
    vector<Todo> todos;

public:
    void bookTicket(const Ticket& ticket) {
        bookedTickets.push_back(ticket);
        cout << "Ticket booked successfully!" << endl;
    }

    void displayBookedTickets() {
        if (bookedTickets.empty()) {
            cout << "No tickets booked yet!" << endl;
        } else {
            cout << "Booked Tickets:" << endl;
            for (const auto& ticket : bookedTickets) {
                cout << "------------------------" << endl;
                cout << "Destination: " << ticket.destination << endl;
                cout << "Date: " << ticket.date.day << "/" << ticket.date.month << "/" << ticket.date.year << endl;
                cout << "Time: " << ticket.time << endl;
                cout << "Price: " << ticket.price << endl;
                cout << "------------------------" << endl;
            }
        }
    }

    void addTodo(const string& task) {
        Todo todo;
        todo.task = task;
        todo.done = false;
        todos.push_back(todo);
        cout << "Todo added successfully!" << endl;
    }

    void displayTodos() {
        if (todos.empty()) {
            cout << "No todos added yet!" << endl;
        } else {
            cout << "Todos:" << endl;
            for (const auto& todo : todos) {
                cout << "Task: " << todo.task << endl;
                cout << "Status: " << (todo.done ? "Done" : "Not Done") << endl;
                cout << "------------------------" << endl;
            }
        }
    }

    void markTodoAsDone(int index) {
        if (index >= 0 && index < todos.size()) {
            todos[index].done = true;
            cout << "Todo marked as done!" << endl;
        } else {
            cout << "Invalid todo index!" << endl;
        }
    }

    void deleteTodo(int index) {
        if (index >= 0 && index < todos.size()) {
            todos.erase(todos.begin() + index);
            cout << "Todo deleted successfully!" << endl;
        } else {
            cout << "Invalid todo index!" << endl;
        }
    }
};

int main() {
    LoginSystem loginSystem;
    TicketBookingSystem bookingSystem;
    string username, password;
    int option;
    int login; 

    do {
        login = loginOption(); 

        if (login == 1) {  
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;

            if (username == "admin" && password == "admin123") {
                do {
                    
                    cout << "Options:\n";
                    cout << "1) View tickets\n";
                    cout << "2) Add tickets\n";
                    cout << "3) Delete tickets\n";
                    cout << "4) Exit\n";
                    cout << "Choose an option: ";
                    cin >> option;

                    switch (option) {
                        case 1: {
                            loginSystem.displayTickets();
                            break;
                        }
                        case 2: {
                            Ticket ticket;
                            cout << "Enter Departure: ";
                            cin >> ticket.departure;
                            cout << "Enter Destination: ";
                            cin >> ticket.destination;
                            cout << "Enter Day (DD): ";
                            cin >> ticket.date.day;
                            cout << "Enter Month (MM): ";
                            cin >> ticket.date.month;
                            cout << "Enter Year (YYYY): ";
                            cin >> ticket.date.year;
                            cout << "Enter Time: ";
                            cin >> ticket.time;
                            cout << "Enter Price: ";
                            cin >> ticket.price;
                            loginSystem.addTicket(ticket);
                            break;
                        }
                        case 3: {
                            int index;
                            cout << "Enter ticket index: ";
                            cin >> index;
                            loginSystem.deleteTicket(index);
                            break;
                        }
                        case 4: {
                            cout << "Exiting..." << endl;
                            break;
                        }
                        default: {
                            cout << "Invalid option!" << endl;
                            break;
                        }
                    }
                } while (option != 4);
            } else {
                cout << "Invalid username or password!" << endl;
            }
        } else if (login == 2) {  // User
            do {               
                cout << "Options:\n";
                cout << "1) Buy Ticket\n";
                cout << "2) View Ticket History\n";
                cout << "3) Todo List\n";
                cout << "4) Exit\n";
                cout << "Choose an option: ";
                cin >> option;

                switch (option) {
                    case 1: {
                        loginSystem.displayTickets();
                        int index;
                        cout << "Enter the index of desired ticket: ";
                        cin >> index;
                        Ticket ticket = loginSystem.getTicket(index);
                        bookingSystem.bookTicket(ticket);
                        break;
                    }
                    case 2: {
                        bookingSystem.displayBookedTickets();
                        break;
                    }
                    case 3: {
                        int todoOption;
                        do {
                            cout << "Todo List Options:\n";
                            cout << "1) Add Todo\n";
                            cout << "2) View Todos\n";
                            cout << "3) Mark Todo as Done\n";
                            cout << "4) Delete Todo\n";
                            cout << "5) Go Back\n";
                            cout << "Choose an option: ";
                            cin >> todoOption;

                            switch (todoOption) {
                                case 1: {
                                    string task;
                                    cout << "Enter todo task: ";
                                    cin.ignore();
                                    getline(cin, task);
                                    bookingSystem.addTodo(task);
                                    break;
                                }
                                case 2: {
                                    bookingSystem.displayTodos();
                                    break;
                                }
                                case 3: {
                                    int index;
                                    cout << "Enter todo index: ";
                                    cin >> index;
                                    bookingSystem.markTodoAsDone(index);
                                    break;
                                }
                                case 4: {
                                    int index;
                                    cout << "Enter todo index: ";
                                    cin >> index;
                                    bookingSystem.deleteTodo(index);
                                    break;
                                }
                                case 5: {
                                    break;
                                }
                                default: {
                                    cout << "Invalid option!" << endl;
                                    break;
                                }
                            }
                        } while (todoOption != 5);
                        break;
                    }
                    case 4: {
                        cout << "Exiting..." << endl;
                        break;
                    }
                    default: {
                        cout << "Invalid option!" << endl;
                        break;
                    }
                }
            } while (option != 4);
        }
    } while (login != 3);

    return 0;
}