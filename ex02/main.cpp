#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib> // for rand()
#include <ctime> // for time()

Base* generate(void){
	int r = std::rand() % 3;
	if (r==0) return new A;
	if (r==1) return new B;
	else return new C;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p)) std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p)) std::cout << "C" << std::endl;
	//Evaluation check: should check if cast return is NULL
}

void identify(Base& p){
	//Evaluation check: use try/catch and no pointers
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return;
	} catch (...) {}
	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return;
	} catch (...) {}
	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return;
	} catch (...) {}

}

int main() {
	std::srand(std::time(0));
	Base* ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete(ptr);
	return 0;
}