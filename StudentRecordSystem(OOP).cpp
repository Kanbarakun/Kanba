#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base class Person
class Person {
protected:
    string name;
    int age;
public:
    Person() {} // Default constructor
    Person(string n, int a) : name(n), age(a) {}

    virtual void displayInfo() {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
};

// Derived class Student inherits from Person
class Student : public Person {
private:
    int studentID;
    string course;
public:
    Student(string n, int a, int id, string c) : Person(n, a) {
        studentID = id;
        course = c;
    }

    void displayInfo() override {
        cout << "Student ID: " << studentID << endl;
        Person::displayInfo();
        cout << "Course: " << course << endl;
    }

    int getID() {
        return studentID;
    }
};

int main() {
    vector<Student> database;
    int choice;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Add Student\n";
        cout << "2. Show All Students\n";
        cout << "3. Search by ID\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cin.ignore();
            string name, course;
            int age, id;

            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter student ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter course: ";
            getline(cin, course);

            Student s(name, age, id, course);
            database.push_back(s);

            cout << "Student added successfully!\n";
        }
        else if (choice == 2) {
            if (database.empty()) {
                cout << "No students available.\n";
            } else {
                for (Student& s : database) {
                    s.displayInfo();
                    cout << "------------------\n";
                }
            }
        }
        else if (choice == 3) {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;

            bool found = false;
            for (Student& s : database) {
                if (s.getID() == id) {
                    s.displayInfo();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student not found.\n";
            }
        }
        else if (choice == 4) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
