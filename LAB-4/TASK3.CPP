#include <iostream>
#include <vector>
#include <string>

using namespace std;

void addRow(vector<vector<string>>& spreadsheet) {
   vector<string> newRow;
   string cell;
   cout << "Enter cells for the new row (press Enter after each cell, 'q' to finish): " << endl;
   while (true) {
       getline(cin, cell);
       if (cell == "q") break;
       newRow.push_back(cell);
   }
   spreadsheet.push_back(newRow);
}

void deleteRow(vector<vector<string>>& spreadsheet) {
   int rowIndex;
   cout << "Enter the row index to delete (0-based): ";
   cin >> rowIndex;
   if (rowIndex >= 0 && rowIndex < spreadsheet.size()) {
       spreadsheet.erase(spreadsheet.begin() + rowIndex);
       cout << "Row deleted successfully." << endl;
   } else {
       cout << "Invalid row index." << endl;
   }
}

void displaySpreadsheet(const vector<vector<string>>& spreadsheet) {
   for (const auto& row : spreadsheet) {
       for (const auto& cell : row) {
           cout << cell << "\t";
       }
       cout << endl;
   }
}

int main() {
   vector<vector<string>> spreadsheet = {
       {"Name", "Age", "City"},
       {"John", "25", "New York"},
       {"Jane", "30", "London"}
   };

   int choice;
   do {
       cout << "1. Add a new row" << endl;
       cout << "2. Delete a row" << endl;
       cout << "3. Display spreadsheet" << endl;
       cout << "4. Exit" << endl;
       cout << "Enter your choice: ";
       cin >> choice;

       switch (choice) {
           case 1:
               addRow(spreadsheet);
               break;
           case 2:
               deleteRow(spreadsheet);
               break;
           case 3:
               displaySpreadsheet(spreadsheet);
               break;
           case 4:
               cout << "Exiting..." << endl;
               break;
           default:
               cout << "Invalid choice. Try again." << endl;
       }
   } while (choice != 4);

   return 0;
}