// Cow.hpp
#pragma once

#include "Animal.hpp"

class Cow : public Animal {
public:
    Cow(std::string name, double temp, double breath, double heart, double liters);
    ~Cow() override = default;

    bool check_health() const override;

private:
    double liters;
};

