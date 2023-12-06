// Vet.cpp
#include "Vet.hpp"
#include <iostream>  // Для std::cout

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Cow.hpp"

// Реализация метода get_instance
Vet& Vet::get_instance() {
    static Vet instance;
    return instance;
}

// Реализация конструктора
Vet::Vet() : animals() {
    // Возможные инициализации, если необходимо
}

// Реализация деструктора
Vet::~Vet() {
    // Освобождение ресурсов, если необходимо
}

// Реализация метода add_animal
void Vet::add_animal(Animal* &&animal) {
    animals.push_back(std::unique_ptr<Animal>(animal));
}

// В Vet.cpp
void Vet::show_sick() const {
    for (const auto &animal : animals) {
	    if(!animal->check_health())
	    {
		    std::cout << animal->name << " ";
	    }

    }
    std::cout << std::endl;
}

void Vet::show_sick_dogs() const {
    for (const auto &animal : animals) {
        auto dog = dynamic_cast<Dog*>(animal.get());
        if (dog && !animal->check_health()) {
            std::cout << dog->name << " ";
        }
    }
    std::cout << std::endl;
}



/*
// В классе Vet в Vet.cpp
void Vet::show_sick() const {
    for (const auto& animal : animals) {
        std::cout << animal->get_name() << " ";
    }
    std::cout << std::endl;
}

void Vet::show_sick_dogs() const {
    for (const auto& animal : animals) {
        // Проверяем, является ли текущее животное экземпляром Dog
        // и является ли оно большой собакой
        if (dynamic_cast<Dog*>(animal.get()) && !animal->check_health()) {
            std::cout << animal->get_name() << " ";
        }
    }
    std::cout << std::endl;
}
*/

/*
// Реализация метода show_sick
void Vet::show_sick() const {
    for (const auto& animal : animals) {
        if (!animal->check_health()) {
            //std::cout << animal->get_name() << " ";
            std::cout << animal->name << " ";
        }
    }
    std::cout << std::endl;
}

// Реализация метода show_sick_dogs
void Vet::show_sick_dogs() const {
    for (const auto& animal : animals) {
        if (dynamic_cast<Dog*>(animal.get()) && !animal->check_health()) {
            //std::cout << animal->get_name() << " ";
            std::cout << animal->name << " ";
        }
    }
    std::cout << std::endl;
}
*/
