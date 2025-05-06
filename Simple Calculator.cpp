#include <iostream>
#include <sstream>
#include <limits>

using namespace std;

// Arithmetic operations
double add(double a, double b)       { return a + b; }
double subtract(double a, double b)  { return a - b; }
double multiply(double a, double b)  { return a * b; }
double divide(double a, double b) {
    if (b == 0) {
        cout << "Cannot divide by zero.\n";
        return 0;
    }
    return a / b;
}

// Evaluate expression like "5 + 3"
bool evaluateExpression(const string& input) {
    double num1, num2;
    char op;
    stringstream ss(input);

    ss >> num1 >> op >> num2;

    // Check for bad format
    if (ss.fail() || !ss.eof()) {
        cout << "Invalid format! Please enter like this: 5 + 3\n";
        return false;
    }

    switch (op) {
        case '+':
            cout << "Result: " << add(num1, num2) << endl;
            break;
        case '-':
            cout << "Result: " << subtract(num1, num2) << endl;
            break;
        case '*':
            cout << "Result: " << multiply(num1, num2) << endl;
            break;
        case '/':
            cout << "Result: " << divide(num1, num2) << endl;
            break;
        default:
            cout << "Invalid operator! Use +, -, *, or /\n";
            return false;
    }
    return true;
}

int main() {
    string input;

    cout << "=== Simple Calculator (Type 'exit' to quit) ===\n";
    while (true) {
        cout << "Enter expression (e.g., 5 + 3): ";
        getline(cin, input);

        if (input == "exit")
            break;

        evaluateExpression(input);
        cout << endl;
    }

    return 0;
}
