#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, string> contacts;

    contacts["John Doe"] = "123-456-7890";
    contacts["Jane Doe"] = "098-765-4321";
    contacts["Jim Doe"] = "111-222-3333";

    string name = "Jane Doe";
    if (contacts.find(name) != contacts.end()) {
        cout << "Contact: " << name << ", Phone: " << contacts[name] << endl;
    } else {
        cout << "Contact not found." << endl;
    }

    return 0;
}