#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>	//For strtod
#include <climits>	//For INT_MIN/INT_MAX
#include <cmath>	//For isnan, isinf
#include <iomanip>	//For setprecision

void ScalarConverter::convert(const std::string& literal) {
	// 1. Type detection Logic
	//		Determine if literal is char, int, float, double or pseudo-literal (nan, nanf, +inf, -inf, +inff, -inff)

	// 2. Parsing
	//		Convert the string to a 'double' or 'long double' first to check for overflows before casting.
	char* endptr;
	double val = std::strtod(literal.c_str(), &endptr);

	// 3. Handling outputs (The 4 Scalar Types)
	// 		--- CHAR ---
	// 		If the value is NaN, Inf, or out of char range (0-127), print "impossible"[cite: 247, 255].
	// 		If it's a valid char but not printable (e.g., 0-31), print "Non displayable"[cite: 232, 250].

	// 		--- INT ---
	// 		Use static_cast<int>(val)[cite: 59].
	// 		If val is nan or exceeds INT_MIN/INT_MAX, print "impossible"[cite: 247].

	// 		--- FLOAT ---
	// 		Use static_cast<float>(val)[cite: 59].
	// 		Format output to show at least one decimal (e.g., 42.0f)[cite: 252].

	// 		--- DOUBLE ---
	// 		Use static_cast<double>(val)[cite: 59].
	// 		Ensure pseudo-literals (nan, inf) are handled correctly[cite: 240, 258].
}

// ScalarConverter::ScalarConverter() {}
// ScalarConverter::ScalarConverter(const ScalarConverter& src) {*this = src;}
// ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {if (this != &rhs) { } return *this;}
// ScalarConverter::~ScalarConverter() {}
