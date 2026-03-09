#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>	//For strtod
#include <climits>	//For INT_MIN/INT_MAX
#include <cmath>	//For isnan, isinf
#include <iomanip>	//For setprecision

void ScalarConverter::convert(const std::string& literal) {
	// 1. Type detection Logic
	//		Determine if literal is char, int, float, double or pseudo-literal (nan, nanf, inf, +inf, -inf, inff, +inff, -inff)
	//		'f' vs 'ffff'
	//		Check for Char: If the string length is 1 and it is not a digit, it is a char.
	//		Check for Pseudo-literals: Check if the string is exactly "nan", "inf", "+inf", "-inf" (doubles) or "nanf", "inff", "+inff", "-inff" (floats).
	//		Check for Float: Now you check for the 'f'. However, a string like "ffff" also ends in 'f' but isn't a number. You should verify that it contains digits and exactly one decimal point.
	//		Check for Double/Int: If it has a decimal point but no 'f', it’s a double. If it only contains digits (and potentially a leading + or -), it’s an int.

	// 2. Parsing
	//		Special case (single non-digit character)
	if (literal.length() == 1 && !std::isdigit(literal[0])) {
		char c = literal[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
		return;
	}
	//		Convert the string to a 'double' or 'long double' first to check for overflows before casting.
	char* endptr;
	double val = std::strtod(literal.c_str(), &endptr);

	//		Check if it's float literal (ends with 'f')
	std::string	str = literal;
	bool isFloatSuffix = (*endptr == 'f' && *(endptr + 1) == '\0');
	bool isEndOfStr = (*endptr == '\0');

	if (!isEndOfStr && !isFloatSuffix) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
}

	// 3. Handling outputs (The 4 Scalar Types)
	// 		--- CHAR ---
	// 		If the value is NaN, Inf, or out of char range (0-127), print "impossible"
	// 		If it's a valid char but not printable (e.g., 0-31), print "Non displayable"
	std::cout << "char: ";
	if (std::isnan(val) || std::isinf(val) || val < 0 || val > 127) {
		std::cout << "impossible" << std::endl;
	}	else if (!std::isprint(static_cast<int>(val))) {
		std::cout << "Non displayable" << std::endl;
	}	else {
		std::cout << "'" << static_cast<char>(val) << "'" << std::endl;
	}

	// 		--- INT ---
	// 		Use static_cast<int>(val)
	// 		If val is nan or exceeds INT_MIN/INT_MAX, print "impossible"
	std::cout << "int: ";
	if (std::isnan(val) || std::isinf(val) || val < INT_MIN || val > INT_MAX) {
		std::cout << "impossible" << std::endl;
	} else {
		std::cout << static_cast<int>(val) << std::endl;
	}

	// 		--- FLOAT ---
	// 		Use static_cast<float>(val)
	// 		Format output to show at least one decimal (e.g., 42.0f)
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f" << std::endl;

	// 		--- DOUBLE ---
	// 		Use static_cast<double>(val)
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(val) << std::endl;
}

// ScalarConverter::ScalarConverter() {}
// ScalarConverter::ScalarConverter(const ScalarConverter& src) {*this = src;}
// ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {if (this != &rhs) { } return *this;}
// ScalarConverter::~ScalarConverter() {}
