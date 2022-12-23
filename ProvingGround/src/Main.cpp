#include <iostream>

#include "EquinoxSTD.h"

#include "LogTester.h"

int main()
{
	std::cout << "Start" << std::endl;

	LogTester logTests;
	logTests.testAll();

	std::cout << "End" << std::endl;
	std::cin.get();
	return 0;
}