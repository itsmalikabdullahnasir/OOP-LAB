#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Dog {
private:
    string name;
    int age;
public:
    Dog(string n, int a) : name(n), age(a) {}

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    void display() const {
        cout << "Dog: " << name << ", Age: " << age << endl;
    }
};

class Person {
private:
    string name;
    int age;
    Dog* dog;
public:
    Person(string n, int a) : name(n), age(a), dog(nullptr) {}

    ~Person() {
        delete dog;
    }

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    void setDog(Dog* newDog) {
        delete dog; // Delete previous dog if exists
        dog = newDog;
    }

    void display() const {
        cout << "Person: " << name << ", Age: " << age;
        if (dog != nullptr) {
            cout << ", Owned Dog: " << dog->getName();
        }
        cout << endl;
    }
};

class House {
private:
    string address;
    Person* occupant;
public:
    House(string addr) : address(addr), occupant(nullptr) {}

    ~House() {
        delete occupant;
    }

    string getAddress() const {
        return address;
    }

    void setOccupant(Person* person) {
        occupant = person;
    }

    void display() const {
        cout << "House Address: " << address << endl;
        if (occupant != nullptr) {
            cout << "Occupant: ";
            occupant->display();
        } else {
            cout << "No occupant." << endl;
        }
    }
};

class Neighborhood {
private:
    vector<House*> houses;
public:
    void addHouse(House* house) {
        houses.push_back(house);
    }

    void display() const {
        cout << "Neighborhood Information:" << endl;
        for (const auto& house : houses) {
            house->display();
            cout << endl;
        }
    }
};

int main() {
    Neighborhood neighborhood;

    House* house1 = new House("123 Main St");
    House* house2 = new House("456 Elm St");

    Person* person1 = new Person("John", 30);
    Person* person2 = new Person("Alice", 25);
    Dog* dog1 = new Dog("Buddy", 5);
    Dog* dog2 = new Dog("Max", 3);

    person1->setDog(dog1);
    person2->setDog(dog2);

    house1->setOccupant(person1);
    house2->setOccupant(person2);

    neighborhood.addHouse(house1);
    neighborhood.addHouse(house2);

    neighborhood.display();

    // Memory cleanup
    delete house1;
    delete house2;
    delete person1;
    delete person2;
    delete dog1;
    delete dog2;

    return 0;
}