#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"

int main() {
	Data myData;
	myData.id = 42;
	myData.name = "CPP Serialization";
	myData.active = true;

	std::cout << "Original Pointer: " << &myData << std::endl;

	// 1. Serialize
	uintptr_t raw = Serializer::serialize(&myData);
	std::cout << "Serialized (uintptr_t): " << raw << std::endl;

	// 2. Deserialize
	Data* ptr = Serializer::deserialize(raw);
	std::cout << "Deserialized Pointer: " << ptr << std::endl;

	// 3. Validation
	if (ptr == &myData){
		std::cout << GREEN << "SUCCESS:" << RESET << " The pointers match!" << std::endl;
		std::cout << "Data check: " << ptr->name << " (ID: " << ptr->id << ")" << std::endl;
	} else {
		std::cout << RED << "FAILURE:" << RESET << " The pointers do NOT match!" << std::endl;

	}
	return 0;
}