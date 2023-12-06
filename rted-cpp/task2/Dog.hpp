// Dog.hpp
#pragma once

#include "Animal.hpp"

class Dog : public Animal {
public:
    Dog(std::string name, double temp, double breath, double heart, bool is_large);
    ~Dog() override = default;

    bool check_health() const override;

private:
    bool is_large;
};

