#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h> //for uintptr_t
#include "Data.hpp"

class Serializer {
	private:
		Serializer();									// Default constructor
		Serializer(const Serializer& src);				// Copy constructor
		Serializer& operator=(const Serializer& rhs);	// Copy assignment operator
		~Serializer();									// Destructor

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP