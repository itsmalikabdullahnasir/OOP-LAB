#include <iostream>
#include <memory>

class Animal {
public:
    virtual ~Animal() = default;
    virtual void makeSound() const = 0;
};

class Lion : public Animal {
public:
    void makeSound() const override {
        std::cout << "Roar!" << std::endl;
    }
};

class Elephant : public Animal {
public:
    void makeSound() const override {
        std::cout << "Trumpet!" << std::endl;
    }
};

class Monkey : public Animal {
public:
    void makeSound() const override {
        std::cout << "Ooh ooh!" << std::endl;
    }
};

class Bird : public Animal {
public:
    void makeSound() const override {
        std::cout << "Chirp!" << std::endl;
    }
};

void hearSound(const Animal& animal) {
    animal.makeSound();
}

int main() {
    std::unique_ptr<Animal> lion = std::make_unique<Lion>();
    std::unique_ptr<Animal> elephant = std::make_unique<Elephant>();
    std::unique_ptr<Animal> monkey = std::make_unique<Monkey>();
    std::unique_ptr<Animal> bird = std::make_unique<Bird>();

    hearSound(*lion);
    hearSound(*elephant);
    hearSound(*monkey);
    hearSound(*bird);

    return 0;
}