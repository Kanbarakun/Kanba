#include <iostream>
#include <string>
#include <algorithm> // for sort
#include <cctype>    // for tolower
using namespace std;

// Function to convert a string to lowercase (for case-insensitive comparison)
string toLowerCase(const string& str) {
    string lower;
    for (char ch : str) {
        lower += tolower(ch); // convert each character to lowercase
    }
    return lower;
}

// Custom comparison function for case-insensitive sorting
bool compareIgnoreCase(const string& a, const string& b) {
    return toLowerCase(a) < toLowerCase(b);
}

int main() {
    string names[5];

    // Input names
    cout << "Enter 5 names:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Name " << i + 1 << ": ";
        getline(cin, names[i]);
    }

    // Sort names using case-insensitive comparison
    sort(names, names + 5, compareIgnoreCase);

    // Display sorted names
    cout << "\nSorted names (case-insensitive):\n";
    for (int i = 0; i < 5; i++) {
        cout << names[i] << endl;
    }

    return 0;
}
