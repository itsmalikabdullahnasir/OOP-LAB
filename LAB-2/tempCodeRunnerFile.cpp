#include <iostream>

class Animal {
public:
    virtual void makeSound() const = 0;
};

class Lion : public Animal {
public:
    void makeSound() const override {
        std::cout << "lion = Roar!\n";
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
        std::cout << "Ooh ooh!\n";
    }
};


void hearSound(const Animal& animal) {
    animal.makeSound();
}


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