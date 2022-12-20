#include <iostream>

#include "EquinoxSTD.h"

#include "Tester.h"

int main()
{
	std::cout << "Start" << std::endl;

	eqx::Log::setLevel(eqx::Log::Level::warning);

	std::cout << std::abs(std::numeric_limits<int>::lowest()) << std::endl;

	Tester test;
	test.testAll();

	std::cout << "End" << std::endl;
	std::cin.get();
	return 0;
}