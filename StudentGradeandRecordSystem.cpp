#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person() {}
    Person(string n, int a) : name(n), age(a) {}

    virtual void displayInfo() {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }

    string getName() const { return name; }
};

class Student : public Person {
private:
    int studentID;
    string course;
    int math, english, science;
public:
    Student(string n, int a, int id, string c, int m, int e, int s)
        : Person(n, a), studentID(id), course(c), math(m), english(e), science(s) {}

    void displayInfo() override {
        cout << "Student ID: " << studentID << endl;
        Person::displayInfo();
        cout << "Course: " << course << endl;
        cout << "Math Grade: " << math << endl;
        cout << "English Grade: " << english << endl;
        cout << "Science Grade: " << science << endl;
        int average = (math + english + science) / 3;
        cout << "Average: " << average << endl;
        cout << "Remarks: " << (average <= 74 ? "Failed" : (average <= 89 ? "Passed" : "Excellent")) << endl;
    }

    int getID() const { return studentID; }
};

int getValidatedInt(string prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (!cin.fail()) break;
        cout << "Invalid input. Please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return value;
}

int getValidatedGrade(string subject) {
    int grade;
    do {
        grade = getValidatedInt("Enter " + subject + " grade (0-99): ");
        if (grade < 0 || grade > 99) cout << "Grade must be between 0 and 99.\n";
    } while (grade < 0 || grade > 99);
    return grade;
}

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

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a valid number.\n";
            continue;
        }

        if (choice == 1) {
            cin.ignore(); // clear buffer
            string name, course;
            int age, id;

            cout << "Enter name: ";
            getline(cin, name);
            age = getValidatedInt("Enter age: ");
            id = getValidatedInt("Enter student ID: ");
            cout << "Enter course: ";
            getline(cin, course);

            int math = getValidatedGrade("Math");
            int english = getValidatedGrade("English");
            int science = getValidatedGrade("Science");

            database.emplace_back(name, age, id, course, math, english, science);
            cout << "Student added successfully!\n";

        } else if (choice == 2) {
            if (database.empty()) {
                cout << "No students available.\n";
            } else {
                for (Student& s : database) {
                    s.displayInfo();
                    cout << "------------------\n";
                }
            }

        } else if (choice == 3) {
            int id = getValidatedInt("Enter ID to search: ");
            bool found = false;
            for (Student& s : database) {
                if (s.getID() == id) {
                    s.displayInfo();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Student not found.\n";

        } else if (choice == 4) {
            cout << "Exiting...\n";
        } else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
