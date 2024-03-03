#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> grades; // Vector to store student grades

    // Function to display menu
    auto displayMenu = []() {
        cout << "\nMenu:\n"
             << "1. Add a grade\n"
             << "2. Display all grades\n"
             << "3. Exit\n"
             << "Enter your choice: ";
    };

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch(choice) {
            case 1: {
                int grade;
                cout << "Enter the grade: ";
                cin >> grade;
                grades.push_back(grade); // Adding a grade
                break;
            }
            case 2: {
                cout << "Student Grades: ";
                for (int grade : grades) {
                    cout << grade << " ";
                }
                cout << endl;
                break;
            }
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
