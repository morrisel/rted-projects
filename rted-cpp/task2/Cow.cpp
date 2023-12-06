// Cow.cpp
#include "Cow.hpp"

Cow::Cow(std::string name, double temp, double breath, double heart, double liters)
    : Animal(std::move(name), temp, breath, heart), liters(liters) {}

bool Cow::check_health() const {
    return temp >= 38.5 && temp <= 39.5 && breath >= 26 && breath <= 50 && heart >= 48 && heart <= 84 && liters >= 30;
}

