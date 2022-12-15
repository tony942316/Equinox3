#include <iostream>

#include "EquinoxSTD.h"

#include "Tester.h"

int main()
{
	std::cout << "Start" << std::endl;

	eqx::Log::setLevel(eqx::Log::Level::warning);

	Tester test;
	test.testAll();

	std::cout << "End" << std::endl;
	std::cin.get();
	return 0;
}