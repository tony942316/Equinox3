#include <iostream>

#include "EquinoxSTD.h"

#include "Tester.h"

int main()
{
	std::cout << "Start" << std::endl;

	Tester test;
	test.testAll();
	eqx::Random::randInt(0, 10);
	eqx::Random::randDouble(0.0, 10.0);

	std::cout << "End" << std::endl;
	std::cin.get();
	return 0;
}