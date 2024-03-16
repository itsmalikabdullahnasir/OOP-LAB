#include <iostream>
#include <string>

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
        cout << "Person: " << name << ", Age: " << age << endl;
        if (dog != nullptr) {
            cout << "Owned Dog: " << dog->getName() << endl;
        }
    }
};

int main() {
    Person person("John", 30);
    Dog* dog1 = new Dog("Buddy", 5);

    cout << "Before changing dog:" << endl;
    person.display();

    cout << "\nIntroducing a new dog..." << endl;
    Dog* dog2 = new Dog("Max", 3);
    person.setDog(dog2);

    cout << "\nAfter changing dog:" << endl;
    person.display();

    delete dog1;
    delete dog2;

    return 0;
}
