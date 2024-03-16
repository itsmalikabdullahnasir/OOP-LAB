#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    void display() const {
        cout << "Person: " << name << ", Age: " << age << endl;
    }
};

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

class House {
private:
    string address;
public:
    House(string addr) : address(addr) {}

    string getAddress() const {
        return address;
    }

    void display() const {
        cout << "House Address: " << address << endl;
    }
};

int main() {
    Person person("Abdullah Nasir", 30);
    Dog dog("Dave", 5);
    House house("House No.120 , Street No.06");

    cout << "Details of the Person:" << endl;
    person.display();

    cout << "\nDetails of the Dog:" << endl;
    dog.display();

    cout << "\nDetails of the House:" << endl;
    house.display();

    return 0;
}
