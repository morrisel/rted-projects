#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cmath>
#include <limits>

// quadratic_equation.hpp
#include "quadratic_equation.hpp"


// Implementation of the private function
void Equation::update_solutions()
{
	double discriminant = b * b - 4 * a * c;

	if (discriminant > 0)
	{
		solutions_size = 2;
		solutions[0] = (-b + std::sqrt(discriminant)) / (2 * a);
		solutions[1] = (-b - std::sqrt(discriminant)) / (2 * a);
	}
	else if (discriminant == 0)
	{
		solutions_size = 1;
		solutions[0] = -b / (2 * a);
	}
	else
	{
		solutions_size = 0;
	}
}

// Implementation of the Equation class
// ------------------------------------
// Implementation the Constructors and Destructor of the Equation class
Equation::Equation(double a, double b, double c)
	: a(a), b(b), c(c), solutions(nullptr), solutions_size(0)
{
	if (a == 0)
	{
		throw std::invalid_argument("Coefficient 'a' cannot be zero.");
	}
	solutions = new double[2];
	update_solutions();
}

Equation::~Equation()
{
	delete[] solutions;
}

Equation::Equation(const Equation &other)
	: a(other.a), b(other.b), c(other.c), solutions(nullptr), solutions_size(other.solutions_size)
{
	solutions = new double[2];
	std::copy(other.solutions, other.solutions + other.solutions_size, solutions);
}

Equation& Equation::operator=(const Equation &other)
{
	if (this != &other)
	{
		delete[] solutions;
		a = other.a;
		b = other.b;
		c = other.c;
		solutions_size = other.solutions_size;
		solutions = new double[2];
		std::copy(other.solutions, other.solutions + other.solutions_size, solutions);
	}
	return *this;
}

// Implementation getters of the Equation class
double Equation::get_a() const { return a; }
double Equation::get_b() const { return b; }
double Equation::get_c() const { return c; }

size_t Equation::get_solutions_size() const { return solutions_size; }
const double *Equation::get_solutions() const { return solutions; }

// Implementation setters of the Equation class
void Equation::set_a(double new_a)
{
	if (new_a == 0)
	{
		throw std::invalid_argument("Coefficient 'a' cannot be zero.");
	}
	a = new_a;
	update_solutions();
}

void Equation::set_b(double new_b)
{
	b = new_b;
	update_solutions();
}

void Equation::set_c(double new_c)
{
	c = new_c;
	update_solutions();
}


// Implementation of the friend functions
Equation operator+(const Equation& eq, double value)
{
	return Equation(eq.a, eq.b, eq.c + value);
}

Equation operator+(double value, const Equation& eq)
{
	return Equation(eq.a, eq.b, eq.c + value);
}

Equation operator+(const Equation& eq1, const Equation& eq2)
{
	return Equation(eq1.a + eq2.a, eq1.b + eq2.b, eq1.c + eq2.c);
}

bool isInteger(double num)
{
	return std::abs(num - std::round(num)) < std::numeric_limits<double>::epsilon();
}

std::ostream& operator<<(std::ostream& os, const Equation& eq)
{
	os << std::fixed;

	if (isInteger(eq.a))
	{
		os << std::setprecision(0) << eq.a;
	}
	else
	{
		os << std::setprecision(1) << eq.a;
	}

	os << " X^2 + ";

	if (isInteger(eq.b))
	{
		os << std::setprecision(0) << eq.b;
	}
	else
	{
		os << std::setprecision(1) << eq.b;
	}

	os << " X + ";

	if (isInteger(eq.c))
	{
		os << std::setprecision(0) << eq.c;
	}
	else
	{
		os << std::setprecision(1) << eq.c;
	}

	os << " = 0";

	return os;
}


int main()
{
	using namespace std;

	Equation eq(10.2, 20.7, 30);
	cout << eq << endl;
	// should print: 10X^2 + 20X + 30 = 0
	cout << eq.get_solutions_size() << endl;
	// should print 0

	eq = -20 + eq;
	cout << eq << endl;
	// should print: 10X^2 + 20X + 10 = 0
	cout << eq.get_solutions_size() << endl;
	// should print 1
	cout << "X1 = " << eq.get_solutions()[0] << endl;
	// should print: X1 = -1

	cout << Equation(1, 5, 3) + Equation(2, 6, 4) << endl;
	// should print: 3X^2 + 11X + 7 = 0

	eq = Equation(1.2, 3, -4.52);
	cout << eq << endl;
	// should print 1X^2 + 3X + -4 = 0
	cout << eq.get_solutions_size() << endl;
	// should print 2
	cout << "X1 = " << eq.get_solutions()[0] << endl;
	// should print: X1 = 1
	cout << "X2 = " << eq.get_solutions()[1] << endl;
	// should print: X2 = -4

	return 0;
}
