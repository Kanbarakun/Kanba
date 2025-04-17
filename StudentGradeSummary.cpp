#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    vector<string> students;
    vector<int> math_grades;
    vector<int> english_grades;
    vector<int> science_grades;
    char choices;

    do
    {
        int num_of_students;

        do {
            cout << "How many students? (1 to " << 12 - students.size() << " only): ";
            cin >> num_of_students;

            if (num_of_students < 1 || num_of_students > 12 - students.size()) {
                cout << "Invalid! You can only put up to 1 to 12 students total.\n";
            }
        } while (num_of_students < 1 || num_of_students > 12 - students.size());

        for (int i = 0; i < num_of_students; i++)
        {
            cout << "\n[Student " << students.size() + 1 << "]\n";

            string name;
            cin.ignore();
            cout << "Enter name: ";
            getline(cin, name);
            students.push_back(name);

            int grade;

            do {
                cout << "Enter Math grade: ";
                cin >> grade;
                if (grade < 0 || grade > 99) cout << "Invalid Number! Try again.\n";
            } while (grade < 0 || grade > 99);
            math_grades.push_back(grade);

            do {
                cout << "Enter Science grade: ";
                cin >> grade;
                if (grade < 0 || grade > 99) cout << "Invalid Number! Try again.\n";
            } while (grade < 0 || grade > 99);
            science_grades.push_back(grade);

            do {
                cout << "Enter English grade: ";
                cin >> grade;
                if (grade < 0 || grade > 99) cout << "Invalid! Try again.\n";
            } while (grade < 0 || grade > 99);
            english_grades.push_back(grade);
        }

        if (students.size() < 12) {
            cout << "\nDo you want to input more students? (Y/N): ";
            cin >> choices;
        } else {
            cout << "\nYou have reached the maximum of 12 students.\n";
            choices = 'N';
        }

    } while (choices == 'Y' || choices == 'y');

    cout << "\n--- STUDENT GRADE SUMMARY ---\n";

    cout << left << setw(25) << "Name"
         << setw(10) << "Math"
         << setw(10) << "Science"
         << setw(10) << "English"
         << setw(10) << "Average"
         << setw(10) << "Remarks" << endl;

    for (int i = 0; i < students.size(); i++)
    {
        int math = math_grades[i];
        int science = science_grades[   ];
        int english = english_grades[i];
        int average = (math + science + english) / 3;

        string remark;
        if (average <= 74) remark = "Failed";
        else if (average <= 89) remark = "Passed";
        else remark = "Excellent";

        cout << left << setw(25) << students[i]
             << setw(10) << math
             << setw(10) << science
             << setw(10) << english
             << setw(10) << average
             << setw(10) << remark << endl;
    }

    return 0;
}
