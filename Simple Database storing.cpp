#include <iostream>
#include <vector>
#include <string>
using namespace std;

// A structure to store user data
struct User {
    string name;
    int age;
    string email;
};

int main() {
    vector<User> database; // Vector to store all users
    int option;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Add User\n";
        cout << "2. Show All Users\n";
        cout << "3. Exit\n";
        cout << "Enter your option: ";
        cin >> option;

        if (option == 1) {
            User newUser;
            cin.ignore(); // clear input buffer

            cout << "Enter name: ";
            getline(cin, newUser.name);

            cout << "Enter age: ";
            cin >> newUser.age;

            cin.ignore(); // clear newline
            cout << "Enter email: ";
            getline(cin, newUser.email);

            // Add user to the database
            database.push_back(newUser);

            cout << "User added successfully!\n";
        } 
        else if (option == 2) {
            if (database.empty()) {
                cout << "No users stored yet.\n";
            } else {
                cout << "\n--- STORED USERS ---\n";
                for (int i = 0; i < database.size(); i++) {
                    cout << "User #" << i + 1 << endl;
                    cout << "Name : " << database[i].name << endl;
                    cout << "Age  : " << database[i].age << endl;
                    cout << "Email: " << database[i].email << endl;
                    cout << "-------------------------\n";
                }
            }
        }
        else if (option == 3) {
            cout << "Exiting program. Goodbye!\n";
        }
        else {
            cout << "Invalid option. Please try again.\n";
        }

    } while (option != 3);

    return 0;
}
