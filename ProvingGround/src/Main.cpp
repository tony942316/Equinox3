#include <iostream>

#include "EquinoxSTD.h"

#include "Tester.h"

int main()
{
	std::cout << "Start" << std::endl;

	Tester tests;
	//tests.testAll();

	eqx::Point<double> loc(-560'126.0, 1'714.0);
	std::cout << eqx::angle(loc) << std::endl;

	std::cout << "End" << std::endl;
	std::cin.get();
	return 0;
}