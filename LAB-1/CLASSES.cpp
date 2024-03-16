#include <iostream>
#include <string>
using namespace std;

class Dog {
private:
    string name;
    string breed;
    int age;

public:
    // Constructor
    Dog(string _name, string _breed, int _age) : name(_name), breed(_breed), age(_age) {}

    // Method to display dog's details
    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Breed: " << breed << endl;
        cout << "Age: " << age << " years" << endl;
    }
};

int main() {
    // Creating a Dog object
    Dog myDog("Buddy", "Labrador Retriever", 3);

    // Displaying dog's details
    myDog.displayDetails();

    return 0;
}
