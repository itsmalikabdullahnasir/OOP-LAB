#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    // Constructor
    Person(string _name, int _age) : name(_name), age(_age) {}

    // Method to display person's details
    void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class House {
private:
    vector<Person> residents;

public:
    // Method to add a person to the house
    void addPerson(const Person& person) {
        residents.push_back(person);
    }

    // Method to display all persons' details in the house
    void displayResidents() {
        cout << "Persons in the House:" << endl;
        for (Person person : residents) {
            person.displayDetails();
        }
    }
};

int main() {
    // Creating persons
    Person person1("Alice", 30);
    Person person2("Bob", 35);

    // Creating a house
    House myHouse;

    // Adding persons to the house
    myHouse.addPerson(person1);
    myHouse.addPerson(person2);

    // Displaying all persons' details in the house
    myHouse.displayResidents();

    return 0;
}

