// Animal.hpp
#pragma once

#include <string>

class Animal {
public:
    std::string name;
    double temp;
    double breath;
    double heart;

    Animal(std::string name, double temp, double breath, double heart);

    virtual bool check_health() const = 0;

    virtual ~Animal() = default;

};

