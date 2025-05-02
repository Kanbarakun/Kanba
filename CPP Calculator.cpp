#include <iostream>
#include <limits>

using namespace std;

int validint(string prompt)
{
    int valid;
    while(true){
    cout << prompt;
    cin >> valid;
    if(!cin.fail()) break;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid! Please enter a number!\n";
    }
    return valid;
}

   int add(int, int b);
   int subtract(int a, int b);
   int multiply(int a, int b);
   float divide (int a, int b);

int main()
{ 
    int choice, num1, num2;

    do{

        num1 = validint("Enter First Number: ");
        num2 = validint("Enter Second Number: ");

    cout << "\nChoose Operation: ";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication.\n";
    cout << "4. Divsion.\n";
    cout << "5. Exit." << endl;
    cout << "Choice: ";
    choice = validint("Enter Choice: ");

    switch (choice)
    {
    case 1:
        cout << "Result: " << add(num1, num2) << endl; 
        break;
    case 2:
       cout << "Result: " << subtract(num1 ,num2) << endl;
       break;
    case 3:
       cout << "Result: " << multiply(num1, num2) << endl;
       break;
    case 4:
       cout << "Result: " << divide(num1, num2) << endl;
       break;
    default:
    cout << "Invalid or Exit..\n";
    }

    }while(choice != 5);


  return 0;


}

int add(int a, int b)
{
  return a + b;   
}

int subtract(int a, int b){
    return a - b;
}

int multiply(int a, int b){
    return a * b;
}

float divide(int a, int b){
    if (b==0){
    cout << "cannot be divide by zero.\n";
    return 0;
   }
   return(float)a/b;
}
