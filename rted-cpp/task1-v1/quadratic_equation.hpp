// quadratic_equation.hpp
#ifndef QUADRATIC_EQUATION_HPP
#define QUADRATIC_EQUATION_HPP

#include <iostream>
#include <limits>
#include <iomanip>
#include <stdexcept>
#include <cmath>

class Equation
{
private:
    double a;
    double b;
    double c;
    double *solutions;
    std::size_t solutions_size;

    void update_solutions();

public:
    Equation(double a, double b, double c);
    ~Equation();
    Equation(const Equation &other);
    Equation &operator=(const Equation &other);

    double get_a() const;
    double get_b() const;
    double get_c() const;
    std::size_t get_solutions_size() const;
    const double *get_solutions() const;

    void set_a(double new_a);
    void set_b(double new_b);
    void set_c(double new_c);

    friend Equation operator+(const Equation &eq, double value);
    friend Equation operator+(double value, const Equation &eq);
    friend Equation operator+(const Equation &eq1, const Equation &eq2);

    friend std::ostream &operator<<(std::ostream &os, const Equation &eq);
};

#endif // QUADRATIC_EQUATION_HPP

