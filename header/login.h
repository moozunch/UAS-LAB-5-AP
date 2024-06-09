#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int loginOption()
{
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

bool containsDigit(const string &checkValue)
{
    for (const char c : checkValue)
    {
        if (isdigit(c))
        {
            return true;
        }
    }

    return false;
}

bool statusLogin(const char *username, const char *savedUsername, const char *password, const char *savedPassword)
{
    if (strcasecmp(username, savedUsername) == 0 && strcmp(password, savedPassword) == 0)
    {
        return true;
    }

    return false;
}

bool timeValidation(const string &checkValue)
{
    if (checkValue.size() != 5 || checkValue[2] != ':')
    {
        return true;
    }

    for (int i = 0; i < checkValue.size(); i++)
    {
        if (i != 2 && !isdigit(checkValue[i]))
        {
            return true;
        }
    }

    int hour = stoi(checkValue.substr(0, 2));
    int minute = stoi(checkValue.substr(3, 5));

    if (hour < 0 || hour > 23 || minute < 0 || minute > 59)
    {
        return true;
    }

    return false;
}

bool isValidDate(int day, int month, int year)
{
    if (year != 2024 || month < 1 || month > 12 || day < 1 || day > 31)
    {
        return true;
    }
    else if (month == 2)
    {
        return day > 29;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return day > 30;
    }
    else
    {
        return day > 31;
    }
    return false;
}