    #include <iostream>
    #include <fstream>
    #include <string>
    #include <iomanip>
    #include <vector>
    #include <ctime>
    #include <sstream>
    #include <algorithm>
    #include "Include/json.hpp"
    using namespace std;
    using json = nlohmann::json;
    int global_id = 1;

    string getCurrentTimestamp() {
        time_t now = time(nullptr);
        tm* local = localtime(&now);
        stringstream ss;
        ss << put_time(local, "%Y-%m-%d %H:%M:%S");
        return ss.str();
    }

    // Structure to store student data
    struct Student {
        int id;
        string name;
        string section;
        int math;
        int science;
        int english;
        string remarks;
        string created_at;
        string updated_at;
    };

    // Function prototypes
    void addStudent(vector<Student>& students);
    void searchStudent(const vector<Student>& students);
    void searchSection(const vector<Student>& students);
    void viewStudents(const vector<Student>& students);
    void updateStudent(vector<Student>& students);
    void deleteStudent(vector<Student>& students);
    void saveStudents(const vector<Student>& students);
    void loadStudents(vector<Student>& students);
    string calculateRemarks(int grade);
    void displayAnalytics(const vector<Student>& students);
    double calculateMean(const vector<int>& grades);
    int findMax(const vector<int>& grades);
    int findMin(const vector<int>& grades);

    // function case-sensitive
    string tolowercase(const string& str){
        string lowstr = str;
        transform(lowstr.begin(), lowstr.end(), lowstr.begin(), ::tolower);
        return lowstr;
    }

    // function to validate Input
    int ValidInput(const string& prompt){
        int value;
        while(true){
            cout << prompt;
            cin >> value;
            if(!cin.fail()) break;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid! Please enter a number.\n";
        }
        return value;
    }

    // function for input grades
    int ValidGrade(const string& subject){
        int grade;
        do
        {
            grade = ValidInput("Enter" + subject + " Grade(0 - 100): ");
            if(grade < 0 || grade > 100) cout << "Invalid! Grade must be between 0 - 100\n";
        } while (grade < 0 || grade > 100);
        return grade;
    }
    int main() {
        vector<Student> students;
        loadStudents(students);

        int choice;
        do {
            cout << "\n--- GRADE ANALYTICS DASHBOARD ---\n";
            cout << "1. Add Student\n";
            cout << "2. View Students\n";
            cout << "3. Update Student\n";
            cout << "4. Delete Student\n";
            cout << "5. Search section\n";
            cout << "6. Search Student\n";
            cout << "7. View Analytics\n";
            cout << "8. Exit\n";
            choice = ValidInput("Enter Choice: ");

            switch (choice) {
                case 1: addStudent(students); break;
                case 2: viewStudents(students); break;
                case 3: updateStudent(students); break;
                case 4: deleteStudent(students); break;
                case 5: searchSection(students); break;
                case 6: searchStudent(students); break; 
                case 7: displayAnalytics(students); break;
                case 8: saveStudents(students); cout << "Exiting...\n"; break;
                default: cout << "Invalid choice. Try again.\n";
            }

        } while (choice != 8);  

        return 0;
    }

    // Function to search for a student by name
    void searchStudent(const vector<Student>& students) {
        string searchName;
        cout << "Enter student name to search: ";
        cin.ignore();
        getline(cin, searchName);

        bool found = false;
        cout << "\n--- Search Results ---\n";
        for (const auto& s : students) {
            if (tolowercase(s.name).find(tolowercase(searchName)) != string::npos) {
                cout << "Name: " << s.name
                    << " | Section: " << s.section
                    << " | Math: " << s.math
                    << " | Science: " << s.science
                    << " | English: " << s.english
                    << " | Remarks: " << s.remarks << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "No students found with the name containing \"" << searchName << "\".\n";
        }
    }
    // function to searh for student sectinosn
    void searchSection(const vector<Student>& students){
        string searchSection;
        cout << "Enter section to search: ";
        cin.ignore();
        getline(cin, searchSection);

        bool found = false;
        cout << "\n---- Search Section Results ---\n";
        for (const auto&s : students){
            if(tolowercase(s.section) == tolowercase(searchSection)){
                cout << "Name: " << s.name
                    << " | Section: " << s.section
                    << " | Math: " << s.math
                    << " | Science: " << s.science
                    << " | English: " << s.english
                    << " | Remarks: " << s.remarks << endl;
            found = true;
            }
        }

        if(!found){
            cout << "No students found in section \"" << searchSection << "\".\n";
        }
    }
    // Function to add a student
    void addStudent(vector<Student>& students) {
        Student s;
        s.id = global_id++;
        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, s.name);

        cout << "Enter section: ";
        getline(cin, s.section);

        s.math = ValidGrade(" Math");
        s.science = ValidGrade(" Science");
        s.english = ValidGrade(" English");

        s.remarks = calculateRemarks((s.math + s.science + s.english) / 3);
        s.created_at = getCurrentTimestamp();
        s.updated_at = s.created_at;

        students.push_back(s);
        saveStudents(students);
        cout << "Student added successfully!\n";
    }

    // Function to view all students
    void viewStudents(const vector<Student>& students) {
        cout << "\n--- Student Records ---\n";
        for (const auto& s : students) {
            cout << "Name: " << s.name
                << " | Section: " << s.section
                << " | Math: " << s.math
                << " | Science: " << s.science
                << " | English: " << s.english
                << " | Remarks: " << s.remarks << endl;
        }
    }

    // Function to update student (names, section, grades)
    void updateStudent(vector<Student>& students) {
        string name;
        cout << "Enter student name to update: ";
        cin.ignore();
        getline(cin, name);

        for (auto& s : students) {
            if (tolowercase(s.name) == tolowercase(name)) {
                cout << "\n--- Current Record ---\n";
                cout << "Name: " << s.name
                    << " | Section: " << s.section
                    << " | Math: " << s.math
                    << " | Science: " << s.science
                    << " | English: " << s.english
                    << " | Remarks: " << s.remarks << "\n\n";

                string newName, newSection;
                cout << "Enter new name (or press Enter to keep current): ";
                getline(cin, newName);
                if (!newName.empty()) s.name = newName;

                cout << "Enter new section (or press Enter to keep current): ";
                getline(cin, newSection);
                if (!newSection.empty()) s.section = newSection;

                s.math = ValidGrade(" Math");
                s.science = ValidGrade(" Science");
                s.english = ValidGrade(" English");

                s.remarks = calculateRemarks((s.math + s.science + s.english) / 3);
                s.updated_at = getCurrentTimestamp();
                saveStudents(students);
                cout << "Student updated successfully!\n";
                return;
            }
        }
        cout << "Student not found.\n";
    }


    // Function to delete a student
    void deleteStudent(vector<Student>& students) {
        string name;
        cout << "Enter student name to delete: ";
        cin.ignore();
        getline(cin, name);

        for (auto it = students.begin(); it != students.end(); ++it) {
            if (tolowercase(it->name) == tolowercase(name)) {
                students.erase(it);
                saveStudents(students);
                cout << "Student deleted successfully!\n";
                return;
            }
        }
        cout << "Student not found.\n";
    }

    // Function to save students to JSON file
  void saveStudents(const vector<Student>& students) {
    json j;
    for (const auto& s : students) {
        j.push_back({
            {"name", s.name},
            {"section", s.section},
            {"math", s.math},
            {"science", s.science},
            {"english", s.english},
            {"remarks", s.remarks},
            {"created_at", s.created_at},
            {"updated_at", s.updated_at}
        });
    }

    // Save to main file
    ofstream file("students.json");
    file << setw(4) << j << endl;
    file.close();

    // Also save to backup file
    ofstream backup("students_backup.json");
    backup << setw(4) << j << endl;
    backup.close();
}


    // Function to load students from JSON file
    void loadStudents(vector<Student>& students) {
    ifstream file("students.json");
    if (file.is_open()) {
        try {
            json j;
            file >> j;
            for (const auto& item : j) {
                Student s;
                s.name = item["name"];
                s.section = item["section"];
                s.math = item["math"];
                s.science = item["science"];
                s.english = item["english"];
                s.remarks = item["remarks"];
                s.created_at = item.value("created_at", getCurrentTimestamp());
                s.updated_at = item.value("updated_at", getCurrentTimestamp());
                students.push_back(s);
                if (s.id >= global_id) global_id = s.id + 1;
            }
            return; // loaded successfully
        } catch (...) {
            cout << "⚠️ Error loading 'students.json'. Trying to restore from backup...\n";
        }
    }

    // If main fails, try loading from backup
    ifstream backupFile("students_backup.json");
    if (backupFile.is_open()) {
        try {
            json j;
            backupFile >> j;
            for (const auto& item : j) {
                Student s;
                s.name = item["name"];
                s.section = item["section"];
                s.math = item["math"];
                s.science = item["science"];
                s.english = item["english"];
                s.remarks = item["remarks"];
                s.created_at = item.value("created_at", getCurrentTimestamp());
                s.updated_at = item.value("updated_at", getCurrentTimestamp());
                students.push_back(s);
                if (s.id >= global_id) global_id = s.id + 1;
            }
            cout << "Restored data from 'students_backup.json'.\n";
            return;
        } catch (...) {
            cout << "Backup data is also corrupted. Starting with empty database.\n";
        }
    }

    students.clear();
    saveStudents(students); // Save empty list to initialize
}


    // Function to calculate remarks based on average grade
    string calculateRemarks(int grade) {
        if (grade >= 90) return "Excellent";
        if (grade >= 75) return "Good";
        return "Needs Improvement";
    }

    // Function to display grade analytics
    void displayAnalytics(const vector<Student>& students) {
        vector<int> math, science, english;

        for (const auto& s : students) {
            math.push_back(s.math);
            science.push_back(s.science);
            english.push_back(s.english);
        }

        cout << "\n--- Grade Analytics ---\n";
        cout << "Math - High: " << findMax(math) << ", Low: " << findMin(math) << ", Mean: " << calculateMean(math) << endl;
        cout << "Science - High: " << findMax(science) << ", Low: " << findMin(science) << ", Mean: " << calculateMean(science) << endl;
        cout << "English - High: " << findMax(english) << ", Low: " << findMin(english) << ", Mean: " << calculateMean(english) << endl;
    }

    // Function to calculate mean
    double calculateMean(const vector<int>& grades) {
        if (grades.empty()) return 0;
        double sum = 0;
        for (int g : grades) sum += g;
        return sum / grades.size();
    }

    // Function to find max grade
    int findMax(const vector<int>& grades) {
        return *max_element(grades.begin(), grades.end());
    }

    // Function to find min grade
    int findMin(const vector<int>& grades) {
        return *min_element(grades.begin(), grades.end());
    }
