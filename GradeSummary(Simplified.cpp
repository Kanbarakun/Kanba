#include <iostream>   // for input and output
#include <vector>     // for dynamic arrays (vectors)
#include <string>     // for string type
using namespace std;

int main() {
    vector<string> names;
    vector<int> math, english, science;
    char choice;
    int number_of_students;
    do {
        do{
        cout << "How many students (1 to " << 12 - names.size() << " only): ";
        cin >> number_of_students;
        if(number_of_students < 1 || number_of_students > 12 - names.size())
          cout << "Invalid You can only input up to 12 students only.\n";
        }while(number_of_students < 1 ||number_of_students > 12 - names.size());

        for(int i=0; i < number_of_students; i++)
        {
        cout << "\n[Student " << names.size() + 1 << "]\n";
        string name;
        int m, e, s;

        // Input student name
        cin.ignore(); // clear leftover input
        cout << "Enter student name: ";
        getline(cin, name);
        names.push_back(name);

        // Input Math grade
        cout << "Math grade (0-99): ";
        cin >> m;
        math.push_back(m);

        // Input English grade
        cout << "English grade (0-99): ";
        cin >> e;
        english.push_back(e);

        // Input Science grade
        cout << "Science grade (0-99): ";
        cin >> s;
        science.push_back(s);
        }

        if(names.size() < 12){
            cout << "\nDo you want to input more students? (Y/N): ";
            cin >> choice;
        }
        else{
            cout << "\nYou have reached the maximum amount of students.\n";
            choice = 'N';
        }


    } while (choice == 'Y' || choice == 'y');

    // Print results
    cout << "\n--- STUDENT SUMMARY ---\n";
    for (int i = 0; i < names.size(); i++) 
    {
        int avg = (math[i] + english[i] + science[i]) / 3;
        
        string remarks;
        if(avg <= 74) remarks = "Failed!";
        else if(avg <= 89) remarks = "Passed";
        else remarks = "Excellent";

        cout << names[i] << " - Average: " << avg << " - " << remarks << endl;
    }
    return 0;
}
