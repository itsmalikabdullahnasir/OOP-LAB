#include <iostream>

// Task 1: Basic Inheritance and Abstract Class
class Animal {
public:
    virtual void makeSound() const = 0; // Pure virtual function
};

class Lion : public Animal {
public:
    void makeSound() const override {
        std::cout << "Roar!\n";
    }
};

class Elephant : public Animal {
public:
    void makeSound() const override {
        std::cout << "Trumpet!\n";
    }
};

class Monkey : public Animal {
public:
    void makeSound() const override {
        std::cout << "Ooh ooh aah aah!\n";
    }
};

// Task 2: Polymorphism in Action
void hearSound(const Animal& animal) {
    animal.makeSound();
}

// Task 3: Adding a New Animal Class
class Bird : public Animal {
public:
    void makeSound() const override {
        std::cout << "Chirp!\n";
    }
};

int main() {
    Lion lion;
    Elephant elephant;
    Monkey monkey;
    Bird bird;

    hearSound(lion);
    hearSound(elephant);
    hearSound(monkey);
    hearSound(bird);

    return 0;
}