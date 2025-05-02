// with export into file.txt
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

// Structure to store student data
struct Student {
    string name;
    int math;
    int science;
    int english;
};

// Function declarations
void inputStudents(vector<Student>& students);
void displayDashboard(const vector<Student>& students);
double calculateMean(const vector<int>& grades);
int findMax(const vector<int>& grades);
int findMin(const vector<int>& grades);
void exportToFile(const vector<Student>& students);

int main() {
    vector<Student> students;
    inputStudents(students);
    displayDashboard(students);
    exportToFile(students);
    return 0;
}

// Function to input student data
void inputStudents(vector<Student>& students) {
    int count;
    cout << "Enter number of students: ";
    cin >> count;

    for (int i = 0; i < count; ++i) {
        Student s;
        cout << "\n[Student " << i + 1 << "]\n";
        cin.ignore();
        cout << "Enter name: ";
        getline(cin, s.name);

        cout << "Math grade: ";
        cin >> s.math;
        cout << "Science grade: ";
        cin >> s.science;
        cout << "English grade: ";
        cin >> s.english;

        students.push_back(s);
    }
}

// Function to extract grades from students into a vector
vector<int> getGrades(const vector<Student>& students, string subject) {
    vector<int> result;
    for (const auto& s : students) {
        if (subject == "Math") result.push_back(s.math);
        else if (subject == "Science") result.push_back(s.science);
        else if (subject == "English") result.push_back(s.english);
    }
    return result;
}

// Function to calculate average
double calculateMean(const vector<int>& grades) {
    if (grades.empty()) return 0;
    double sum = 0;
    for (int g : grades) sum += g;
    return sum / grades.size();
}

// Function to find max grade
int findMax(const vector<int>& grades) {
    int max = grades[0];
    for (int g : grades)
        if (g > max) max = g;
    return max;
}

// Function to find min grade
int findMin(const vector<int>& grades) {
    int min = grades[0];
    for (int g : grades)
        if (g < min) min = g;
    return min;
}

// Function to display analytics dashboard
void displayDashboard(const vector<Student>& students) {
    cout << fixed << setprecision(2);
    cout << "\n--- GRADE ANALYTICS DASHBOARD ---\n\n";

    vector<string> subjects = {"Math", "Science", "English"};
    for (const string& subject : subjects) {
        vector<int> grades = getGrades(students, subject);
        cout << subject << ":\n";
        cout << "  Mean: " << calculateMean(grades) << endl;
        cout << "  Highest: " << findMax(grades) << endl;
        cout << "  Lowest: " << findMin(grades) << endl << endl;
    }

    cout << "--- STUDENT RECORDS ---\n";
    cout << left << setw(20) << "Name"
         << setw(10) << "Math"
         << setw(10) << "Science"
         << setw(10) << "English" << endl;

    for (const auto& s : students) {
        cout << left << setw(20) << s.name
             << setw(10) << s.math
             << setw(10) << s.science
             << setw(10) << s.english << endl;
    }
}

// Function to export data to a file
void exportToFile(const vector<Student>& students) {
    ofstream file("grade_report.txt");
    if (!file) {
        cout << "Error writing to file!\n";
        return;
    }

    file << "Student Grade Report\n\n";
    for (const auto& s : students) {
        file << s.name << " - Math: " << s.math
             << ", Science: " << s.science
             << ", English: " << s.english << "\n";
    }

    file.close();
    cout << "\nData exported to 'grade_report.txt'\n";
}

