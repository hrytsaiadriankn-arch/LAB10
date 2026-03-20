#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Friend {
    string surname;
    string name;
    string phone;
    int day, month, year;
};

// Input validation for integers
int inputInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Input error! Try again.\n";
        }
        else {
            cin.ignore(10000, '\n');
            return value;
        }
    }
}

// Add a record to file
void addFriend(const string& filename) {
    ofstream file(filename, ios::app);
    if (!file) {
        cout << "Cannot open file!\n";
        return;
    }

    Friend f;

    cout << "Enter surname: ";
    getline(cin, f.surname);

    cout << "Enter name: ";
    getline(cin, f.name);

    cout << "Enter phone number: ";
    getline(cin, f.phone);

    f.day = inputInt("Birth day: ");
    f.month = inputInt("Birth month: ");
    f.year = inputInt("Birth year: ");

    file << f.surname << " "
        << f.name << " "
        << f.phone << " "
        << f.day << " "
        << f.month << " "
        << f.year << endl;

    file.close();
    cout << "Record added successfully!\n";
}

// View all records
void viewFriends(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "File does not exist!\n";
        return;
    }

    Friend f;

    cout << "\nFriends list:\n";

    while (file >> f.surname >> f.name >> f.phone >> f.day >> f.month >> f.year) {
        cout << "------------------------\n";
        cout << "Surname: " << f.surname << endl;
        cout << "Name: " << f.name << endl;
        cout << "Phone: " << f.phone << endl;
        cout << "Birth date: " << f.day << "."
            << f.month << "." << f.year << endl;
    }

    file.close();
}

// Search by surname
void searchFriend(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "File does not exist!\n";
        return;
    }

    string searchSurname;
    cout << "Enter surname to search: ";
    getline(cin, searchSurname);

    Friend f;
    bool found = false;

    while (file >> f.surname >> f.name >> f.phone >> f.day >> f.month >> f.year) {
        if (f.surname == searchSurname) {
            cout << "\nFound:\n";
            cout << "Name: " << f.name << endl;
            cout << "Phone: " << f.phone << endl;
            cout << "Birth date: " << f.day << "."
                << f.month << "." << f.year << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Record not found!\n";
    }

    file.close();
}

// Main menu
void menu() {
    string filename;
    cout << "Enter file name: ";
    getline(cin, filename);

    int choice;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Add record\n";
        cout << "2. View list\n";
        cout << "3. Search by surname\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";

        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            addFriend(filename);
            break;
        case 2:
            viewFriends(filename);
            break;
        case 3:
            searchFriend(filename);
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);
}

int main() {
    menu();
    return 0;
