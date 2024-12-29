#include <iostream>
#include <cmath> // For handling square root and power functions

using namespace std;

void displayMenu() {
    cout << "Simple Digital Calculator\n";
    cout << "---------------------------\n";
    cout << "1. Add\n";
    cout << "2. Subtract\n";
    cout << "3. Multiply\n";
    cout << "4. Divide\n";
    cout << "5. Square Root\n";
    cout << "6. Power\n";
    cout << "7. Exit\n";
    cout << "Choose an option (1-7): ";
}

int main() {
    int choice;
    double num1, num2, result;

    do {
        displayMenu();
        cin >> choice;

        switch(choice) {
            case 1:
                // Addition
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                result = num1 + num2;
                cout << "Result: " << result << endl;
                break;

            case 2:
                // Subtraction
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                result = num1 - num2;
                cout << "Result: " << result << endl;
                break;

            case 3:
                // Multiplication
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                result = num1 * num2;
                cout << "Result: " << result << endl;
                break;

            case 4:
                // Division
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                if (num2 != 0) {
                    result = num1 / num2;
                    cout << "Result: " << result << endl;
                } else {
                    cout << "Error! Division by zero is not allowed.\n";
                }
                break;

            case 5:
                // Square root
                cout << "Enter a number: ";
                cin >> num1;
                if (num1 >= 0) {
                    result = sqrt(num1);
                    cout << "Square root: " << result << endl;
                } else {
                    cout << "Error! Negative number can't have a square root.\n";
                }
                break;

            case 6:
                // Power
                cout << "Enter base and exponent: ";
                cin >> num1 >> num2;
                result = pow(num1, num2);
                cout << "Result: " << result << endl;
                break;

            case 7:
                cout << "Exiting calculator. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Please select a valid option.\n";
        }

        cout << endl;
    } while (choice != 7);

    return 0;
}
