#include "ScalarConverter.hpp"

void runTests()
{
	std::string tests[] = {
		"0",		  // Int/Double
		"42",		  // Int
		"42.0f",	  // Float
		"42.42",	  // Double
		"a",		  // Char
		"nan",		  // Pseudo-literal double
		"nanf",		  // Pseudo-literal float
		"+inf",		  // Pseudo-literal double
		"-inff",	  // Pseudo-literal float
		"2147483647", // Max Int
		"2147483648", // Int Overflow
		"42ffff",	  // Invalid (should show impossible)
		"   "		  // Invalid
	};

	for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i)
	{
		std::cout << "--- Testing: [" << tests[i] << "] ---" << std::endl;
		ScalarConverter::convert(tests[i]);
		std::cout << std::endl;
	}
}

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Usage: ./convert <literal>" << std::endl;
		return 1;
	}

	std::string input = argv[1];
	if (input == "test_mode")
	{
		runTests();
	} else
	{
	// Calling the static method without instantiating the class
		ScalarConverter::convert(input);
	}
	return 0;
}