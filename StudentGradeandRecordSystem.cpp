#include <iostream>     // for input and output (cin, cout)
#include <vector>       // for using dynamic arrays (vector)
#include <string>       // for using string data type
#include <limits>       // for handling input errors
#include <iomanip>      // for formatting output (optional here)
using namespace std;

// Base class: Person
class Person {
protected:
    string name;    // Protected so Student class can access directly
    int age;
public:
    Person() {} // Default constructor
    Person(string n, int a) : name(n), age(a) {} // Constructor with parameters

    virtual void displayInfo() { // virtual allows overriding in derived classes
        cout << "Name: " << name << "\nAge: " << age << endl;
    }

    string getName() const { return name; } // getter function for name
};

// Derived class: Student inherits from Person
class Student : public Person {
private:
    int studentID;
    string course;
    int math, english, science; // student's grades
public:
    // Constructor: calls the Person constructor for name and age
    Student(string n, int a, int id, string c, int m, int e, int s)
        : Person(n, a), studentID(id), course(c), math(m), english(e), science(s) {}

    // Override displayInfo to show full student data
    void displayInfo() override {
        cout << "Student ID: " << studentID << endl;
        Person::displayInfo(); // call base class function to show name and age
        cout << "Course: " << course << endl;
        cout << "Math Grade: " << math << endl;
        cout << "English Grade: " << english << endl;
        cout << "Science Grade: " << science << endl;
        
        int average = (math + english + science) / 3; // calculate average
        cout << "Average: " << average << endl;
        // Ternary conditional operator (short if-else) to determine remark
        cout << "Remarks: " << (average <= 74 ? "Failed" : (average <= 89 ? "Passed" : "Excellent")) << endl;
    }

    int getID() const { return studentID; } // getter function for ID
};

// Function to safely get a valid integer input
int getValidatedInt(string prompt) {
    int value;
    while (true) { // loop until user inputs a valid number
        cout << prompt;
        cin >> value;
        if (!cin.fail()) break; // if input is good, exit loop
        cout << "Invalid input. Please enter a number.\n";
        cin.clear(); // clears the error state of cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard wrong input from buffer
    }
    return value;
}

// Function to get a validated grade between 0-99
int getValidatedGrade(string subject) {
    int grade;
    do {
        grade = getValidatedInt("Enter " + subject + " grade (0-99): ");
        if (grade < 0 || grade > 99) cout << "Grade must be between 0 and 99.\n";
    } while (grade < 0 || grade > 99); // repeat until valid grade
    return grade;
}

int main() {
    vector<Student> database; // dynamic array to store students
    int choice;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Add Student\n";
        cout << "2. Show All Students\n";
        cout << "3. Search by ID\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail()) { // if user enters wrong type like letter
            cin.clear(); // clear the error
            cin.ignore(1000, '\n'); // ignore wrong input
            cout << "Please enter a valid number.\n";
            continue; // go back to menu
        }

        if (choice == 1) {
            cin.ignore(); // clear leftover newline from buffer

            string name, course;
            int age, id;

            cout << "Enter name: ";
            getline(cin, name); // get full name including spaces
            age = getValidatedInt("Enter age: "); // safe age input
            id = getValidatedInt("Enter student ID: "); // safe id input
            cout << "Enter course: ";
            getline(cin, course);

            // Input grades safely
            int math = getValidatedGrade("Math");
            int english = getValidatedGrade("English");
            int science = getValidatedGrade("Science");

            // Add student to database using emplace_back (constructs in-place)
            database.emplace_back(name, age, id, course, math, english, science);
            cout << "Student added successfully!\n";

        } else if (choice == 2) { // Show all students
            if (database.empty()) { // no students yet
                cout << "No students available.\n";
            } else {
                for (Student& s : database) { // range-based for loop
                    s.displayInfo(); // show each student's info
                    cout << "------------------\n";
                }
            }

        } else if (choice == 3) { // Search student by ID
            int id = getValidatedInt("Enter ID to search: ");
            bool found = false;
            for (Student& s : database) {
                if (s.getID() == id) { // if ID matches
                    s.displayInfo(); // show full student info
                    found = true;
                    break; // stop searching
                }
            }
            if (!found) cout << "Student not found.\n";

        } else if (choice == 4) { // Exit
            cout << "Exiting...\n";
        } else { // if user inputs an invalid menu choice
            cout << "Invalid choice.\n";
        }

    } while (choice != 4); // repeat until user chooses Exit

    return 0;
}
