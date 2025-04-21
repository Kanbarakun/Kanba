#include <iostream>   // for input and output
#include <vector>     // for dynamic arrays (vectors)
#include <string>     // for string type
using namespace std;

int main() {
    vector<string> names;
    vector<int> math, english, science;
    char choice;

    do {
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

        // Ask if user wants to add another student
        cout << "Add another student? (Y/N): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    // Print results
    cout << "\n--- STUDENT SUMMARY ---\n";
    for (int i = 0; i < names.size(); i++) {
        int avg = (math[i] + english[i] + science[i]) / 3;
        string status = (avg >= 90) ? "Excellent" :
                        (avg >= 75) ? "Passed" : "Failed";

        cout << names[i] << " - Average: " << avg << " - " << status << endl;
    }

    return 0;
}
