#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
using namespace std;

int main()
{
    vector <string> students;
    vector <int> math_grades, science_grades, english_grades;
    char choices;
    int number_of_students;
    
    do
    {
        do
        {                      // how much can user input.
            cout << "How many students do you want to input? (1 to " << 12 - students.size() << " only): ";
            cin >> number_of_students;
            if(cin.fail() ||number_of_students < 1 || number_of_students > 12 - students.size())
            {
                cout << "You can only input up to 1 to 12 students only. \n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }while(number_of_students < 1 || number_of_students > 12 - students.size());
        

        for(int i = 0; i < number_of_students; i++)
        {
            
            cout << "\n[STUDENT " << students.size() + 1 << "]\n";
            
            string names;
            int grades;
             // user input
            cin.ignore();
            cout << "Enter name: ";\
            getline(cin, names);
            students.push_back(names);
            
            do
            {
                cout << "Enter Math grades: ";
                cin >> grades;
                if(cin.fail() || grades < 0 || grades > 99)
                while(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid! Please Enter Math grades: ";
                cin >> grades;
                }
            }while(grades < 0 || grades > 99);
            math_grades.push_back(grades);
            
            do
            {
                cout << "Enter Science grades: ";
                cin >> grades;
                if(cin.fail() || grades < 0 || grades > 99)
                while(cin.fail()){ 
                    cout << "Invalid! Try again.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid! Please Enter Science Grade: ";
                    cin >> grades;
                }
            }while(grades < 0 || grades > 99);
            science_grades.push_back(grades);
            
            do
            {
                cout << "Enter English grades: ";
                cin >> grades;
                if(cin.fail() || grades < 0 || grades > 99) 
                while(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Grade! Please enter English grades: ";
                cin >> grades;
                }
            }while(grades < 0 || grades > 99);
            english_grades.push_back(grades);
        }
        // this line here if the user wants to input more student and if he had reached the limit.
        if(students.size() < 12)
        {
            cout << "Do you want to input more students? (Y/N): ";
            cin >> choices;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            cout << "You have reached the maximum amount of students.";
            choices = 'N';
        }
        
    }while(choices == 'Y' || choices == 'y');
      // fixing the width
    cout << "\t\n ----- STUDENT GRADE SUMMARY -----\t\n";
    
    cout << left << setw(25) << "Names"
    << setw(10) << "Math"
    << setw(10) << "Science"
    << setw(10) << "English"
    << setw(10) << "Average"
    << setw(10) << "Remarks" << endl;
    // here calculating the grade summary
    for(int i = 0; i < students.size(); i++)
    {
        int math = math_grades[i];
        int science = science_grades[i];
        int english = english_grades[i];
        int average = (math + science + english) /3;
        // conditional statement whether if your grade is passed or nah
        string remark;
        if(average <= 74) remark = "FAILED";
        else if(average <= 89) remark = "PASSED";
        else remark = "EXCELLENT!";
        
    cout << left << setw(25) << students[i]
    << setw(10) << math
    << setw(10) << science
    << setw(10) << english
    << setw(10) << average
    << setw(10) << remark << endl;
    }
    
    return 0;
}
