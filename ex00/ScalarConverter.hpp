#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class ScalarConverter {
	private:
		ScalarConverter();											// Default constructor
		ScalarConverter(const ScalarConverter& src);				// Copy constructor
		ScalarConverter& operator=(const ScalarConverter& rhs);		// Copy assignment operator
		~ScalarConverter();											// Destructor

	public:
		static void	convert(const std::string& literal);

	
};

#endif // SCALARCONVERTER_HPP