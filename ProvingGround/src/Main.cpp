#include <iostream>

#include "EquinoxSTD.h"

#include "Tester.h"

int main()
{
	std::cout << "Start" << std::endl;

	Tester tests;
	tests.testAll();

	std::cout << "End" << std::endl;
	std::cin.get();
	return 0;
}