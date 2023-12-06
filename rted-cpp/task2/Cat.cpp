// Cat.cpp
#include "Cat.hpp"

Cat::Cat(std::string name, double temp, double breath, double heart)
    : Animal(std::move(name), temp, breath, heart) {}

bool Cat::check_health() const {
    return temp >= 38.0 && temp <= 39.2 && breath >= 16 && breath <= 40 && heart >= 120 && heart <= 140;
}

