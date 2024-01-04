// Vet.hpp
#pragma once

#include <vector>
#include <memory>
#include "Animal.hpp"  // Включаем заголовочный файл Animal.hpp

class Vet {
public:
    static Vet& get_instance();
    void add_animal(Animal* &&animal);
    void show_sick() const;
    void show_sick_dogs() const;

private:
    Vet();  // Приватный конструктор
    ~Vet(); // Приватный деструктор

    Vet(const Vet&) = delete;             // Запрещаем копирование
    Vet& operator=(const Vet&) = delete;

    Vet(Vet&&) = delete;                  // Запрещаем перемещение
    Vet& operator=(Vet&&) = delete;

    std::vector<std::unique_ptr<Animal>> animals;
};

